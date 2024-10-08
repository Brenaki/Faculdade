library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all; 
use IEEE.NUMERIC_STD.ALL;

entity RegisterFile is
  port(clk,rst:           in  STD_LOGIC;
       we:            in  STD_LOGIC;
       ra1, ra2, wa:  in  STD_LOGIC_VECTOR(4 downto 0);
       wd:            in  STD_LOGIC_VECTOR(31 downto 0);
       d1, d2:      out STD_LOGIC_VECTOR(31 downto 0));
end;

architecture behave of RegisterFile is
  type ramtype is array (31 downto 0) of STD_LOGIC_VECTOR(31 downto 0);
  signal mem: ramtype; --:= (others=>(others=>'0'));
  --signal data1, data2: std_logic_vector(31 downto 0) ;
  
begin

  grava: process (clk, rst)
  begin

      if rst='1' then
          mem <= (others=>(others=>'0'));
      end if;

      if  rising_edge(clk) and we = '1' and rst='0' then
          mem(to_integer(unsigned(wa))) <= wd;
      end if;
  end process;
  
  d1 <= X"00000000" when to_integer(unsigned(ra1)) = 0 else mem(to_integer(unsigned(ra1)));
  d2 <= X"00000000" when to_integer(unsigned(ra2)) = 0 else mem(to_integer(unsigned(ra2)));
  


 

  --regfile: process(clk, we, ra1, ra2) 
 -- begin
	--  if rising_edge(clk) and we='1' then
	--  	mem(to_integer(unsigned(wa))) <= wd;
	--  end if;	
	 
--	  if (to_integer(unsigned(ra1)) = 0) then 
 --       data1 <= X"00000000"; -- register 0 holds 0
 --   else	
 --       data1 <= mem(to_integer(unsigned(ra1)));
--	  end if;
	 
--	  if (to_integer(unsigned(ra2)) = 0) then 
--        data2 <= X"00000000";
--	  else 
 --       data2 <= mem(to_integer(unsigned(ra2)));
--	  end if;
	 
--  end process;

  -- atribuição das saidas
  --d1 <= data1;
  --d2 <= data2;
end;