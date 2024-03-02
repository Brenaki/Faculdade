.data
	x: .word 15
	y: .byte 5
	z: .word 0
	
.text
.globl main

main:
	la $s0, x
	la $s1, z
	
	lw $t0, 0($s0)
	lb $t1, 4($s0)
	
	sub $t2, $t0, $t1
	
	sw $t2, 0($s1)