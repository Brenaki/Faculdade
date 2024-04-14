.data
	x: .word -13
	a: .word 0
	
.text
	la $s0, x
	la $s1, a
	
	lw $t0, 0($s0)
	
	# verifica se é 0 antes de deslocar 
	beq $t0, $zero, fim
	
	# desloca bits
	srl $t0, $t0, 31
	
	# verifica se é postivo ou negativo
	beq $t0, $zero, positivo
	
	# se é negativo add 5
	addi $t1, $zero, 5
	j fim
	
	# se é positivo add 10
	positivo: addi $t1, $zero, 10
	
	fim: sw $t1, 0($s1)