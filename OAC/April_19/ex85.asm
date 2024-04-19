.data
	x: .word 5,2,3,4,5,6
.text
	main:	la $s0, x
		li $a0, 0 # Acumula a soma
		
	L1: 	slti $t1, $t0, 6
		beq $t1, $zero, saida
		sll $t1, $t0, 2
		
		add $t1, $t1, $s0
		
		lw $t2, 0($t1)
		
		add $a0, $a0, $t2
		
		addi $t0, $t0, 1
		
		j L1
	
	saida:	li $v0, 1
		syscall
		li $v0, 10
		syscall