library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity reg32 is
PORT ( entrada: in std_logic_vector (31 downto 0);
	clk: in std_logic;
	saida: out std_logic_vector (31 downto 0));
end;


architecture behavioral of reg32 is
signal valor: std_logic_vector (31 downto 0):= X"00000000";
begin
saida <= valor;
atualiza: process (clk)
begin
if rising_edge(clk) then
 	valor <= entrada;
end if;
end process;
end behavioral;

