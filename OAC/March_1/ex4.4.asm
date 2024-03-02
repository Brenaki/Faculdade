.data
	x: .word 0x01020304
	
.text
.globl main

main:
	la $s0, x
	lb $t0, 2($s0)