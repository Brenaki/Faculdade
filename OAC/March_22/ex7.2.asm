.data
	x: .byte 0,1,2,3,5,8
	y: .byte 3,2,3,4,5,6
	z: .space 6
	
.text
	la $s0, x
	la $s1, y
	la $s2, z
	
	add $t0, $zero, $zero
	
	L1: slti $t1, $t0, 6
	beq $t1, $zero, saida
	
	add $t2, $t0, $s0
	add $t3, $t0, $s1
	add $t4, $t0, $s2
	
	lb $t5, 0($t2)
	lb $t6, 0($t3)
	
	add $t7, $t5, $t6
	
	sb $t7, 0($t4)
	
	addi $t0, $t0, 1
	
	j L1
	saida: