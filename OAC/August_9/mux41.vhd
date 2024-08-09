library ieee;
use ieee.std_logic_1164.all;

entity mux41 is
  port (
  A, B, C, D: in STD_LOGIC;
  S0, S1: in STD_LOGIC;
  Y: out STD_LOGIC
  );
end entity mux41;

architecture mux of mux41 is
  signal t0, t1: STD_LOGIC;
begin
   UTT1: entity work.mux21 port map(A,B,S0,t0);
   UTT2: entity work.mux21 port map(C,D,S0,t1);
   UTT3: entity work.mux21 port map(t0,t1,S1,Y);
end architecture mux;
