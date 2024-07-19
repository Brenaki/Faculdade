library ieee;
use ieee.std_logic_1164.all;

entity maioria_tb is
end maioria_tb;

architecture arch of maioria_tb is
	signal A,B,C: std_logic;
	signal Y: std_logic;
	begin
		UUT: entity work.maioria port map (A=>A, B=>B, C=>C, Y=>Y);
		linha_A: process
		begin
			A <= '0';
			wait for 100 ps;
			A <= '1';
			wait for 200 ps;
		end process;
		linha_B: process
		begin
			B <= '0';
			wait for 50 ps;
			B <= '1';
			wait for 150 ps;
		end process;
		linha_C: process
		begin
			C <= '0';
			wait for 150 ps;
			C <= '1';
			wait for 100 ps;
		end process;
	end arch;
