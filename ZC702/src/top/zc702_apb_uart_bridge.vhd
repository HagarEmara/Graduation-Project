------------------------------------------------------------------------------
-- zc702_apb_uart_bridge.vhd
-- Snoops VexRiscv APB bus for UART writes and buffers them in a FIFO
-- ARM reads captured bytes via AXI-Lite at 0x40010000
--
-- Register map (ARM side):
--   0x00 = DATA_AVAIL  (R) number of bytes in FIFO
--   0x04 = DATA_READ   (R) read one byte from FIFO (0xFFFFFFFF if empty)
--
-- APB snooping:
--   Monitors apb_paddr, apb_pwrite, apb_penable, apb_pwdata
--   When VexRiscv writes to APB_UART_WRITE (addr=0x30004), captures byte
------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity zc702_apb_uart_bridge is
  generic (
    C_S_AXI_ADDR_WIDTH : integer := 8;
    C_S_AXI_DATA_WIDTH : integer := 32;
    FIFO_DEPTH         : integer := 256
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

    -- APB snoop inputs (driven by soc_base/VexRiscv)
    apb_paddr     : in  std_logic_vector(19 downto 0);
    apb_pwrite    : in  std_logic;
    apb_penable   : in  std_logic_vector(15 downto 0);
    apb_pwdata    : in  std_logic_vector(31 downto 0)
  );
end entity;

architecture rtl of zc702_apb_uart_bridge is

  -- FIFO
  type fifo_t is array (0 to FIFO_DEPTH-1) of std_logic_vector(7 downto 0);
  signal fifo      : fifo_t := (others => (others => '0'));
  signal wr_ptr    : integer range 0 to FIFO_DEPTH-1 := 0;
  signal rd_ptr    : integer range 0 to FIFO_DEPTH-1 := 0;
  signal fifo_cnt  : integer range 0 to FIFO_DEPTH   := 0;
  signal fifo_full : std_logic;
  signal fifo_empty: std_logic;

  -- APB UART write address = 0x30004 >> 2 = 0xC001 in word address
  -- apb_paddr is 20-bit byte address
  -- APB_UART_WRITE offset = 0x30004
  constant UART_WRITE_ADDR : std_logic_vector(19 downto 0) := x"30004";

  -- AXI-Lite read FSM
  type rd_state_t is (R_IDLE, R_RESP);
  signal rd_state  : rd_state_t := R_IDLE;
  signal rdata_int : std_logic_vector(31 downto 0);
  signal do_read   : std_logic := '0';

  -- AXI-Lite write FSM (writes ignored but need to respond)
  type wr_state_t is (W_IDLE, W_DATA, W_RESP);
  signal wr_state  : wr_state_t := W_IDLE;

begin

  fifo_full  <= '1' when fifo_cnt = FIFO_DEPTH else '0';
  fifo_empty <= '1' when fifo_cnt = 0 else '0';

  -- APB snooper: capture VexRiscv UART writes into FIFO
  process(s_axi_aclk)
  begin
    if rising_edge(s_axi_aclk) then
      if s_axi_aresetn = '0' then
        wr_ptr   <= 0;
        fifo_cnt <= 0;
      else
        -- Detect APB write to UART_WRITE address
        -- apb_penable is a one-hot vector per device, any bit set = active
        if apb_pwrite = '1' and
           apb_penable /= (apb_penable'range => '0') and
           apb_paddr = UART_WRITE_ADDR and
           fifo_full = '0' then
          fifo(wr_ptr) <= apb_pwdata(7 downto 0);
          wr_ptr <= (wr_ptr + 1) mod FIFO_DEPTH;
          if do_read = '0' then
            fifo_cnt <= fifo_cnt + 1;
          end if;
        elsif do_read = '1' and fifo_empty = '0' then
          fifo_cnt <= fifo_cnt - 1;
        end if;
      end if;
    end if;
  end process;

  -- FIFO read pointer advance
  process(s_axi_aclk)
  begin
    if rising_edge(s_axi_aclk) then
      if s_axi_aresetn = '0' then
        rd_ptr <= 0;
      elsif do_read = '1' and fifo_empty = '0' then
        rd_ptr <= (rd_ptr + 1) mod FIFO_DEPTH;
      end if;
    end if;
  end process;

  -- AXI-Lite Read FSM
  process(s_axi_aclk)
  begin
    if rising_edge(s_axi_aclk) then
      do_read <= '0';
      if s_axi_aresetn = '0' then
        rd_state      <= R_IDLE;
        s_axi_arready <= '0';
        s_axi_rvalid  <= '0';
        s_axi_rresp   <= "00";
      else
        case rd_state is
          when R_IDLE =>
            s_axi_rvalid <= '0';
            if s_axi_arvalid = '1' then
              s_axi_arready <= '1';
              case s_axi_araddr(3 downto 2) is
                when "00" =>
                  -- DATA_AVAIL register
                  rdata_int <= std_logic_vector(to_unsigned(fifo_cnt, 32));
                when "01" =>
                  -- DATA_READ register
                  if fifo_empty = '0' then
                    rdata_int <= x"000000" & fifo(rd_ptr);
                    do_read   <= '1';
                  else
                    rdata_int <= x"FFFFFFFF";
                  end if;
                when others =>
                  rdata_int <= (others => '0');
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

  s_axi_rdata <= rdata_int;

  -- AXI-Lite Write FSM (respond OK but ignore data)
  process(s_axi_aclk)
  begin
    if rising_edge(s_axi_aclk) then
      if s_axi_aresetn = '0' then
        wr_state      <= W_IDLE;
        s_axi_awready <= '0';
        s_axi_wready  <= '0';
        s_axi_bvalid  <= '0';
        s_axi_bresp   <= "00";
      else
        case wr_state is
          when W_IDLE =>
            s_axi_bvalid <= '0';
            if s_axi_awvalid = '1' then
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

end architecture;
