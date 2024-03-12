.data
	x: .word 14
	y: .word 0
	
.text
	la $s0, x #$s0 <- endereço de x
	la $s1, y #$s1 <- endereço de y
	
	lw $t0, 0($s0) # $t0 <- 14
	
	sll $t0, $t0, 3 # $t0 <- $t0 deslocado 3 posições a esquerda
	
	sw $t0, 0($s1)