library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity banco is
  port (clk, rst: in std_logic;
        we: in std_logic;
        ra1, ra2, wa: in std_logic_vector(4 downto 0); -- endereços de leitura e endereço de escrita
        wd: in std_logic_vector(31 downto 0);
        d1, d2: out std_logic_vector(31 downto 0)
  );
end entity banco;

architecture behavioral of banco is
  type ramtype is array (31 downto 0) of std_logic_vector(31 downto 0);
  signal mem: ramtype := (others=>(others=>'0'));
  signal data1, data2: std_logic_vector(31 downto 0);
begin
regfile: process(clk, we, ra1, ra2) begin
  if rising_edge(clk) and we='1' then
    mem(to_integer(unsigned(wa))) <= wd;
  end if;

  if(to_integer(unsigned(ra1)) = 0) then
    data1 <= X"00000000"; --register 0 holds 0
  else 
    data1 <= mem(to_integer(unsigned(ra1)));
  end if;

  if(to_integer(unsigned(ra2)) = 0) then
    data2 <= X"00000000";
  else
    data2 <= mem(to_integer(unsigned(ra2)));
  end if;
end process;

d1 <= data1;
d2 <= data2;
  
end architecture behavioral;
