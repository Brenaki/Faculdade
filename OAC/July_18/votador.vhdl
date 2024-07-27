LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY votador IS
	PORT(A, B, C:	IN	STD_LOGIC;
	Y:      OUT STD_LOGIC);
END votador;

ARCHITECTURE eq OF votador IS
BEGIN
  Y <= (A AND B) OR (A AND C) OR (B AND C);
END eq;
