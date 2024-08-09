library ieee;
use ieee.std_logic_1164.all; 

entity mux2132_tb is 
end entity mux2132_tb;

architecture arch of mux2132_tb is
  signal A, B, Y: STD_LOGIC_VECTOR(31 downto 0);
  signal S: STD_LOGIC;
begin
  UTT: entity work.mux2132 port map (A, B, S, Y);
  linha_A: process begin
    A <= x"00000026";
    wait for 200 ps;
    A <= x"00000013";
    wait for 200 ps;
  end process;
  linha_B: process begin
    B <= x"00000013";
    wait for 200 ps;
    B <= x"00000026";
    wait for 200 ps; 
  end process;
  linha_S: process begin
    S <= '1';
    wait for 100 ps;
    S <= '0';
    wait for 100 ps;
    S <= '1';
    wait for 100 ps;
    S <= '0';
    wait for 100 ps;
  end process;
end architecture arch;
