library IEEE;
use IEEE.std_logic_1164.all;

entity controle_tb is
end entity controle_tb;

architecture arch of controle_tb is
  signal OPcode :  STD_LOGIC_VECTOR (5 downto 0);
  signal ALUOp :  STD_LOGIC_VECTOR (1 downto 0);
  signal RegDst :  STD_LOGIC;
  signal ALUSrc :  STD_LOGIC;
  signal MemToReg :  STD_LOGIC;
  signal RegWrite :  STD_LOGIC;
  signal MemRead :  STD_LOGIC;
  signal MemWrite :  STD_LOGIC;
	signal Branch :  STD_LOGIC;
	signal BranchNE : STD_LOGIC;
	signal Jump : STD_LOGIC;
begin
  UTT: entity work.controle port map(OPcode, ALUOp, RegDst, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, BranchNE, Jump);
  control: process
    begin
      OPcode <= "000000";
      wait for 100 ps;
      OPcode <= "100011";
      wait for 100 ps;
      OPcode <= "101011";
      wait for 100 ps;
      OPcode <= "000100";
      wait for 100 ps;
      OPcode <= "000100";
      wait for 100 ps;
      OPcode <= "000101";
      wait for 100 ps;
      OPcode <= "000010";
      wait for 100 ps;
      OPcode <= "001000";
      wait;
    end process;
end architecture arch;
