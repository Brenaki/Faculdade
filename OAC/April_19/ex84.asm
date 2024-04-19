.data
	x: .word 0

.text
		# Abre o pop-up
	main:	li $v0, 5
		syscall
		
		# $a0 <- valor_digitado
		add $a0, $zero, $v0
		
		# Cria o ponteiro de x
		la $s0, x
		
		# Armazena o valor digitado
		sw $a0, 0($s0)
		
		# Imprime o valor
		li $v0, 1
		syscall
		
		# Finaliza o programa
		li $v0, 10
		syscall