.data
	f: .word 10
	g: .word 8
	h: .word 5

.text
	# Cria os endereços das variáveis
	la $s0, f
	la $s1, g
	la $s2, h
	
	# Carrega as variáveis para o "temp"
	lw $t0, 0($s0)
	lw $t1, 0($s1)
	lw $t2, 0($s2)
	
	# F == G adiciona 5, caso contrario dimunui -1
	beq $t0, $t1, entao
	addi $t2, $t2, -1
	
	# Pula para a função "fim"
	j fim
	
	entao: addi $t2, $t2, 5

	fim: sw $t2, 0($s2)