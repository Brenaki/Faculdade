.text
	main:	addi $a0, $a0, 4
		li $v0, 1
		syscall
		# $a0 <- Valor lido
		li $v0, 10
		syscall