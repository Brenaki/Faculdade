library ieee;
use ieee.std_logic_1164.all;

entity mux41_tb is
end entity mux41_tb;

architecture muxG of mux41_tb is
  signal A,B,C,D, S0, S1: STD_LOGIC;
  signal Y: STD_LOGIC;
begin
  UTT: entity work.mux41 port map(A, B, C, D, S0, S1, Y);
    linha_A: process begin
      A <= '0';
      wait for 200 ps;
      A <= '1';
      wait for 200 ps;
    end process;
    linha_B: process begin
      B <= '1';
      wait for 200 ps;
      B <= '0';
      wait for 200 ps;
    end process;
    linha_C: process begin
      C <= '0';
      wait for 200 ps;
      C <= '1';
      wait for 200 ps;
    end process;
    linha_D: process begin
      D <= '1';
      wait for 200 ps;
      D <= '0';
      wait for 200 ps;
    end process;
    linha_S0: process begin
      S0 <= '1';
      wait for 100 ps;
      S0 <= '0';
      wait for 100 ps;
      S0 <= '1';
      wait for 100 ps;
      S0 <= '0';
      wait for 100 ps;
    end process;
    linha_S1: process begin
      S1 <= '1';
      wait for 100 ps;
      S1 <= '0';
      wait for 100 ps;
      S1 <= '1';
      wait for 100 ps;
      S1 <= '0';
      wait for 100 ps;
    end process;
end architecture muxG;
