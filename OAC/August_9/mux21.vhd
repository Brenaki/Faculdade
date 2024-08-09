library ieee;
use ieee.std_logic_1164.all;

entity mux21 is
  port (
  A, B, S: in STD_LOGIC;
  Y: out STD_LOGIC
  );
end entity mux21;

architecture mux of mux21 is
begin
  Y <= A when S='0' else B; 
end architecture mux;
