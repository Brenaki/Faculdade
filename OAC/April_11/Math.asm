.data
	w: .word 1,2,3,4,5,6
	x: .word 8,9,10,11,12,13
	y: .word 0,0,0,0,0,0
	z: .word 0,0,0,0,0,0
.text
	la $s0,w
	la $s1,x
	la $s2,y
	la $s3,z
	
	li $t0,0
	
	loop: 	slti $t1,$t0,6
		beq $t1,$zero,saida
	
		sll $t3,$t0,2
	
	
	multi: 	add $t4,$t3,$s0
		lw $t6, 0($t4)
		mul $t7,$t6,$t6
		add $t5,$t3,$s2 
	
		sw $t7, 0($t5)
		
		
	soma:	add $t4,$t3,$s1
		lw $t6, 0($t4)
		add $t7,$t6,$t6
		add $t5,$t3,$s3
		
		sw $t7, 0($t5)
		
		addi $t0,$t0,1
		j loop	
	saida: