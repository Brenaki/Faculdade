library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity banco_tb is 
end entity banco_tb;

architecture behavioral of banco_tb is
	signal rst: std_logic;
	signal escReg:  STD_LOGIC;
	signal r1, r2, wa: STD_LOGIC_VECTOR(4 downto 0); -- enderecos de leitura e e endereco de escrita
	signal wd:	STD_LOGIC_VECTOR(31 downto 0);
	signal d1, d2: STD_LOGIC_VECTOR(31 downto 0);
	signal clock_50: std_logic;


begin
	U1: entity work.banco PORT MAP (clock_50, rst, escReg, r1, r2, wa, wd, d1, d2);

	relogio: process
    	begin
    	clock_50 <= '0';
    	wait for 50 ps;
    	clock_50 <= '1';
    	wait for 50 ps;

	end process;

testa: process
begin
	escReg <= '0';
	rst <= '0';
	r1 <= "00000"; -- simula leitura do registrador 0
	r2 <= "00000"; -- simula leitura do registrador 0
	wait for 100 ps;
    

	-- simula leitura do $zero
	r1 <= "00000";
	-- simula escrita no registrador 1    
	wa <="00001";
	wd <=x"00000004";
	escReg <= '1';
    
   	 
	r1 <= "00001";
	wait for 100 ps;

	escReg <= '1';
	wa <="00010";
	wd <=x"00000008";
    
	wait for 100 ps;

	escReg <= '0';
	r1 <= "00010";

	wait;



end process;
end;
