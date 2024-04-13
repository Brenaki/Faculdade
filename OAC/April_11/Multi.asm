.data
	x: .word 1,2,3,4,6,8,9
	y: .word 0,0,0,0,0,0,0
.text
	la $s0, x
	la $s1, y
	
	lw $t3, 0($s0)
	li $t0, 0
	
	loop: slti $t1,$t0,7
	beq $t1,$zero,saida
	
	sll $t3,$t0,2
	add $t4,$t3,$s0
	lw $t6, 0($t4)
	mul $t7,$t6,$t6
	add $t5,$t3,$s1
	
	sw $t7, 0($t5)
	addi $t0,$t0,1
	j loop
	
	saida:
