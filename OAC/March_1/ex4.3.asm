.data
	v: .word 0,1,2,3,4,5,6
	alfa: .word 32

.text
.globl main

main:
	la $s0, v
	la $s1, alfa
	
	lw $t0, 0($s1) # $t0 <- alfa
	
	sw $t0, 4($s0) # v[1] <- alfa 
	sw $t0, 12($s0) # v[3] <- alfa
	sw $t0, 20($s0) # v[5] <- alfa