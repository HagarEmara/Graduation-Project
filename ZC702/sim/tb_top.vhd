---------------------------------------------------------------------------
-- Testbench wrapper for ztachip simulation
-- Drives clk and observes led_out from main.vhd
---------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_top is
end tb_top;

architecture sim of tb_top is

   component main is
      port(
         clk     : in  std_logic;
         led_out : out std_logic_vector(3 downto 0)
      );
   end component;

   signal clk     : std_logic := '0';
   signal led_out : std_logic_vector(3 downto 0);

   -- 200 MHz clk_x2_main → 5 ns period
   -- main.vhd internally divides this by 2 → 100 MHz clk_main
   constant CLK_PERIOD : time := 5 ns;

begin

   -- Clock generator
   clk_proc: process
   begin
      clk <= '0';
      wait for CLK_PERIOD/2;
      clk <= '1';
      wait for CLK_PERIOD/2;
   end process;

   -- DUT
   dut: main
      port map(
         clk     => clk,
         led_out => led_out
      );

   -- Monitor process: report when LEDs change
   monitor: process(led_out)
   begin
      report "[t=" & time'image(now) & "] led_out = " &
             std_logic'image(led_out(3)) &
             std_logic'image(led_out(2)) &
             std_logic'image(led_out(1)) &
             std_logic'image(led_out(0));
   end process;

end sim;
