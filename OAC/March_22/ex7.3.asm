.data
	x: .lw 0,1,2,3,5,8
	y: .lw 3,2,3,4,5,6
	z: .space 24
	
.text
	la $s0, x
	la $s1, y
	la $s2, z
	
	add $t0, $zero, $zero
	
	L1: slti $t1, $t0, 6
	beq $t1, $zero, saida
	sll $t1, $t0, 2 # $t1 <- $t0 * 4
	
	add $t2, $s0, $t1
	add $t3, $s1, $t1
	add $t4, $s2, $t1
	
	lw $t5, 0($t2)
	lw $t6, 0($t3)
	
	add $t7, $t5, $t6
	
	sb $t7, 0($t4)
	
	addi $t0, $t0, 1
	
	j L1
	
	saida: