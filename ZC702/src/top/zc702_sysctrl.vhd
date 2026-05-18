------------------------------------------------------------------------------
-- zc702_sysctrl.vhd — ZC702 PS<->PL bring-up control register block
--
-- Minimal AXI-Lite slave (32-bit data, 32-bit addr) exposing 4 registers:
--   0x00  SCRATCH    R/W  Loopback test
--   0x04  LED        R/W  Bits[3:0] -> ZC702 PL LEDs (when CTRL.LED_SRC_SEL=0)
--   0x08  CTRL       R/W  Bit[0]=CPU_RESET (1=hold VexRiscv in reset)
--                         Bit[1]=LED_SRC_SEL (0=ARM, 1=VexRiscv ogpio)
--   0x0C  PB         R    Bits[3:0] = ZC702 PL push-buttons
--
-- Reset values: CTRL=0x00000001 (CPU held in reset, LED source = ARM)
------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity zc702_sysctrl is
  generic (
    C_S_AXI_ADDR_WIDTH : integer := 6;
    C_S_AXI_DATA_WIDTH : integer := 32
  );
  port (
    s_axi_aclk    : in  std_logic;
    s_axi_aresetn : in  std_logic;
    s_axi_awaddr  : in  std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
    s_axi_awprot  : in  std_logic_vector(2 downto 0);
    s_axi_awvalid : in  std_logic;
    s_axi_awready : out std_logic;
    s_axi_wdata   : in  std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
    s_axi_wstrb   : in  std_logic_vector(C_S_AXI_DATA_WIDTH/8-1 downto 0);
    s_axi_wvalid  : in  std_logic;
    s_axi_wready  : out std_logic;
    s_axi_bresp   : out std_logic_vector(1 downto 0);
    s_axi_bvalid  : out std_logic;
    s_axi_bready  : in  std_logic;
    s_axi_araddr  : in  std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);
    s_axi_arprot  : in  std_logic_vector(2 downto 0);
    s_axi_arvalid : in  std_logic;
    s_axi_arready : out std_logic;
    s_axi_rdata   : out std_logic_vector(C_S_AXI_DATA_WIDTH-1 downto 0);
    s_axi_rresp   : out std_logic_vector(1 downto 0);
    s_axi_rvalid  : out std_logic;
    s_axi_rready  : in  std_logic;

    led_arm_out      : out std_logic_vector(3 downto 0);
    led_src_sel_out  : out std_logic;
    cpu_reset_out    : out std_logic;
    pb_in            : in  std_logic_vector(3 downto 0)
  );
end entity;

architecture rtl of zc702_sysctrl is
  signal reg_scratch : std_logic_vector(31 downto 0) := (others => '0');
  signal reg_led     : std_logic_vector(31 downto 0) := (others => '0');
  signal reg_ctrl    : std_logic_vector(31 downto 0) := x"00000001";

  type wr_state_t is (W_IDLE, W_DATA, W_RESP);
  signal wr_state : wr_state_t := W_IDLE;
  signal awaddr_lat : std_logic_vector(C_S_AXI_ADDR_WIDTH-1 downto 0);

  type rd_state_t is (R_IDLE, R_RESP);
  signal rd_state : rd_state_t := R_IDLE;
  signal rdata_int : std_logic_vector(31 downto 0);
begin

  -- Write FSM
  process(s_axi_aclk)
  begin
    if rising_edge(s_axi_aclk) then
      if s_axi_aresetn = '0' then
        wr_state      <= W_IDLE;
        s_axi_awready <= '0';
        s_axi_wready  <= '0';
        s_axi_bvalid  <= '0';
        s_axi_bresp   <= "00";
        reg_scratch   <= (others => '0');
        reg_led       <= (others => '0');
        reg_ctrl      <= x"00000001";
      else
        case wr_state is
          when W_IDLE =>
            s_axi_bvalid <= '0';
            if s_axi_awvalid = '1' then
              awaddr_lat    <= s_axi_awaddr;
              s_axi_awready <= '1';
              s_axi_wready  <= '1';
              wr_state      <= W_DATA;
            else
              s_axi_awready <= '0';
              s_axi_wready  <= '0';
            end if;

          when W_DATA =>
            s_axi_awready <= '0';
            if s_axi_wvalid = '1' then
              s_axi_wready <= '0';
              case awaddr_lat(3 downto 2) is
                when "00" => reg_scratch <= s_axi_wdata;
                when "01" => reg_led     <= s_axi_wdata;
                when "10" => reg_ctrl    <= s_axi_wdata;
                when others => null;
              end case;
              s_axi_bvalid <= '1';
              s_axi_bresp  <= "00";
              wr_state     <= W_RESP;
            end if;

          when W_RESP =>
            if s_axi_bready = '1' then
              s_axi_bvalid <= '0';
              wr_state     <= W_IDLE;
            end if;
        end case;
      end if;
    end if;
  end process;

  -- Read FSM
  process(s_axi_aclk)
  begin
    if rising_edge(s_axi_aclk) then
      if s_axi_aresetn = '0' then
        rd_state      <= R_IDLE;
        s_axi_arready <= '0';
        s_axi_rvalid  <= '0';
        s_axi_rresp   <= "00";
        rdata_int     <= (others => '0');
      else
        case rd_state is
          when R_IDLE =>
            s_axi_rvalid <= '0';
            if s_axi_arvalid = '1' then
              s_axi_arready <= '1';
              case s_axi_araddr(3 downto 2) is
                when "00" => rdata_int <= reg_scratch;
                when "01" => rdata_int <= reg_led;
                when "10" => rdata_int <= reg_ctrl;
                when "11" => rdata_int <= x"0000000" & pb_in;
                when others => rdata_int <= (others => '0');
              end case;
              s_axi_rvalid <= '1';
              s_axi_rresp  <= "00";
              rd_state     <= R_RESP;
            else
              s_axi_arready <= '0';
            end if;

          when R_RESP =>
            s_axi_arready <= '0';
            if s_axi_rready = '1' then
              s_axi_rvalid <= '0';
              rd_state     <= R_IDLE;
            end if;
        end case;
      end if;
    end if;
  end process;

  s_axi_rdata     <= rdata_int;
  led_arm_out     <= reg_led(3 downto 0);
  cpu_reset_out   <= reg_ctrl(0);
  led_src_sel_out <= reg_ctrl(1);

end architecture;
