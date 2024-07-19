library ieee;
use ieee.std_logic_1164.all;

entity maioria is 
	port (A,B,C: in std_logic;
		Y: out std_logic);
end maioria;

architecture arch of maioria is
	begin
  		Y <= (A AND B) OR (A AND C) OR (B AND C);
	end arch;
