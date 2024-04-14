.data 
	alpha: .word 0,1,2,3,5,8,10,11
	beta: .space 32
	
.text
	li $a0, 1
	la $s0, alpha
	la $s1, beta
	
	add $t0, $zero, $zero
	
	L1: slti $t1, $t0, 8
	beq $t1, $zero, saida
	sll $t1, $t0, 2 # $t1 <- $t0 * 4
	
	add $t2, $t1, $s0
	add $t3, $t1, $s1
	
	lw $t4, 0($t2) # $t4 <- a[i]
	
	and $t5, $t4, $a0
	
	sw $t5, 0($t3) # beta[i] <- 0 ou 1
	
	addi $t0, $t0, 1
	
	j L1
	
	saida: