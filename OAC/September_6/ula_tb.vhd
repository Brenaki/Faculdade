library IEEE;
use IEEE.std_logic_1164.all;

entity ula_tb is  
end entity ula_tb;

architecture rtl of ula_tb is
 -- Sinais que a ULA transmite
  signal A_input:     STD_LOGIC_VECTOR(31 DOWNTO 0);
 signal B_input:     STD_LOGIC_VECTOR(31 DOWNTO 0);
 signal Zero:        STD_LOGIC;
 signal ALU_Result:  STD_LOGIC_VECTOR(31 DOWNTO 0);
 signal ALUCtr:     STD_LOGIC_VECTOR(2 DOWNTO 0);

 -- Sinais que a ULACtrl transmite
 signal ALUOp:       STD_LOGIC_VECTOR(1 DOWNTO 0);
 signal Instr:       STD_LOGIC_VECTOR(5 DOWNTO 0); -- Instrução vindo da memória

begin
  ALU: entity work.ALU port map(A_input, B_input, Zero, ALU_Result, ALUCtr);
  ALUCtrl: entity work.ALUCtrl port map(ALUOp, Instr, ALUCtr);
tbULA: process
begin
	A_input <= x"00000001";
	B_input <= x"00000002";

	-- simulação do add
	Instr <= "100000";
	ALUOP <= "10";
	wait for 100 ps;

	-- simulação do sub;  
	A_input <= x"00000003";
	B_input <= x"00000001";

	Instr <= "100010";
	ALUOP <= "10";
	wait for 100 ps;

  -- simulação do and
  A_input <= x"00000002";
  B_input <= x"00000001";

  Instr <= "100100";
  ALUOP <= "10";
  wait for 100 ps;  

  -- simulação do or
  A_input <= x"00000002";
  B_input <= x"00000001";

  Instr <= "100101";
  ALUOP <= "10";
  wait for 100 ps;

  -- simulação do slt
  A_input <= x"00000003";
  B_input <= x"00000005";

  Instr <= "101010";
  ALUOP <= "10";
  wait;
end process; 
end architecture rtl;
