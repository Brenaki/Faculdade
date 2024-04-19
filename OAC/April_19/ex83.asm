.data
	x: .word 13
 
.text
	main:	la $s0, x
		lw $a0, 0($s0)
		li $v0, 1
		syscall
		li $v0, 10
		syscall