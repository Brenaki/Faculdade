library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity testa is
end ;

architecture X of testa is
signal ALUresult :   STD_LOGIC_VECTOR (31 downto 0);
signal Temporario: std_logic_vector(31 downto 0);
signal ctrl: std_logic;
signal wd:    STD_LOGIC_VECTOR(31 downto 0);

begin
U8: entity work.mux2x1 PORT MAP (ALUResult, Temporario, ctrl, wd);
testando: process
begin
	ctrl <= '1';
	Temporario <=  X"00000005";
	ALUresult   <= X"00000009";
	wait for 50 ps;
	ctrl <= '0';
	wait;
end process;



end architecture;
