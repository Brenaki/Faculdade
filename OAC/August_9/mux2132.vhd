library ieee;
use ieee.std_logic_1164.all;

entity mux2132 is
  port (
   A, B: in STD_LOGIC_VECTOR(31 downto 0);
   S: in STD_LOGIC;
   Y: out STD_LOGIC_VECTOR(31 downto 0)
  );
end entity mux2132;

architecture mux32 of mux2132 is
begin
  Y <= A when S='0' else B;
end architecture mux32;
