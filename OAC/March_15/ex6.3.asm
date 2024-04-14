.data
	f: .word 10
	g: .word 8
	h: .word 0

.text
.globl main

	main:
		la $s0, f
		la $s1, g
		la $s2, h
		
		lw $t0, 0($s0)
		lw $t1, 0($s1)
		lw $t2, 0($s2)
		
		slt $t3, $t1, $t0 # $t3 <- 1 se g < f
		beq $t3, $zero, senao
		sub $t2, $t0, $t1
		j fim
		
		senao: move $t2, $t1 # $t2 <- $t1
		
		fim: sw $t2, 0($s2)