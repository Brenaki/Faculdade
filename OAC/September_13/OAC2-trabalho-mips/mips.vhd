library IEEE;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity mips is
end mips;

architecture behavioral of mips is


signal clock: std_logic;
signal rs, rd, rt, wa: STD_LOGIC_VECTOR(4 downto 0); -- enderecos
signal imediato: STD_LOGIC_VECTOR(15 downto 0);
signal campoFuncao: STD_LOGIC_VECTOR(5 downto 0);
signal codigoOperacao: STD_LOGIC_VECTOR(5 downto 0);

signal wd:    STD_LOGIC_VECTOR(31 downto 0);
signal RamDataOut:    STD_LOGIC_VECTOR(31 downto 0);
signal d1, d2: STD_LOGIC_VECTOR(31 downto 0);


signal sinalExtendido: STD_LOGIC_VECTOR(31 downto 0);

signal zero: STD_LOGIC;
signal ALUresult :   STD_LOGIC_VECTOR (31 downto 0);
signal input2ALU: STD_LOGIC_VECTOR(31 downto 0);
signal ALUctrl : std_logic_vector(2 downto 0);
signal ALUOp :  STD_LOGIC_VECTOR (1 downto 0);
signal RegDst : STD_LOGIC;
signal ALUSrc : STD_LOGIC;
signal MemToReg :   STD_LOGIC;
signal RegWrite :   STD_LOGIC;
signal MemRead :  STD_LOGIC;
signal MemWrite:   STD_LOGIC;
signal Branch :   STD_LOGIC;
signal Jump :  STD_LOGIC;
signal BranchNE : std_logic;
signal rst: std_logic;
signal instrucao: STD_LOGIC_VECTOR(31 downto 0);
signal saidaReg: STD_LOGIC_VECTOR(31 downto 0);


begin

	-- separacao dos campos da instrucao
	codigoOperacao <= instrucao(31 downto 26);
	rs <= instrucao(25 downto 21);
	rt <= instrucao(20 downto 16);
	rd <= instrucao(15 downto 11);
	imediato <= instrucao(15 downto 0);
	campoFuncao <= instrucao(5 downto 0);

	-- componentes de projeto hierarquico
	
	U1: entity work.ExtensoraSinal PORT MAP (imediato, sinalExtendido);
	U2: entity work.ALU PORT MAP (d1, input2ALU, zero, ALUresult, ALUctrl);
	U3: entity work.ALUCtrl PORT MAP (ALUOp, campoFuncao, ALUctrl);
	U4: entity work.controle PORT MAP (codigoOperacao, ALUOp, RegDst, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, Jump, BranchNE);
	U5: entity work.banco PORT MAP (clock, rst, RegWrite, rs, rt, wa, wd, d1, d2);
	-- muxes...
	-- Exercicio 2 aqui ...
  -- Read data 2 | Sign extend | ALUSrc | ALU
	U6: entity work.mux2x1 port map (d2, sinalExtendido, ALUSrc, input2ALU);
  -- Instruction[20:16] | Instruction[15:11] | RegDst | Write register
	U7: entity work.mux52x1 port map (rt, rd, RegDst, wa);
  -- ALU result | Read data | MemtoReg | Write data
	U8: entity work.mux2x1 port map (ALUresult, RamDataOut, MemToReg, wd);
	

relogio: process 
	begin
		clock <= '0';
		wait for 50 ps;
		clock <= '1';
		wait for 50 ps;
	end process;

testa: process
	
	begin
		
		rst <= '0';
		RamDataOut <= X"00000000";
		wait for 200 ps;
	
		-- dois addis para setar o valor inicial dos registradores
		-- instrucao <= "001000 01000 01001 0000000000000001"; addi
		-- instrucao <= "00100001000010010000000000000101"; --- addi
		instrucao <= "00100000000010000000000000000001"; -- addi $t0 = 1
    wait for 100 ps;
		instrucao <= "00100000000010010000000000000010"; -- addi $t1 = 2
		wait for 100 ps;
    instrucao <= "00100000000010100000000000000011"; -- addi $t2 = 3
    wait for 100 ps;
    instrucao <= "00100000000011000000000000000001"; -- addi $t3 = 1
    wait for 100 ps;

		-- exercicio 3 aqui
        
    
    -- instrucao <= "000000 01001 01010 01000 00000 010000" == add $t0, $t1, $t2
    instrucao <= "00000001001010100100000000100000"; -- add
    wait for 100 ps;
    -- instrucao <= "000000 01001 01010 01000 00000 100010" == sub $t0, $t1, $t2
    instrucao <= "00000001000011000101000000100010"; -- sub
    wait for 100 ps;
    
		
	end process;
end behavioral;
