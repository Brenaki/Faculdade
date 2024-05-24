.data
	ln: .asciiz "\n"
	equals: .asciiz "="
	msg: .asciiz "Fibonacci"
	msg1: .asciiz "Gold Number"
	tb: .asciiz "\t"

.text
main:	li $t2, 0
	li $t3, 1
	
	# Titles
		# Fibonacci
		la $a0, msg
		li $v0, 4
		syscall

		# \t
		la $a0, tb
		li $v0, 4
		syscall
		
		# Gold Number
		la $a0, msg1
		li $v0, 4
		syscall
		
		# /n
		la $a0, ln
		li $v0, 4
		syscall
	
	add $t0, $zero, $zero
	
	# printf("1");
	move $a0, $t3
	li $v0, 1
	syscall
	
	# /n
	la $a0, ln
	li $v0, 4
	syscall
	
	loop:	slti $t1, $t0, 20
		beq $t1, $zero, saida
		
		add $t4, $t2, $t3
		move $t2, $t3
		move $t3, $t4
		
		# Fibonacci
		move $a0, $t3
		li $v0, 1
		syscall
		
		# \t
		la $a0, tb
		li $v0, 4
		syscall
		
		# equals
		la $a0, equals
		li $v0, 4
		syscall
		
		# \t
		la $a0, tb
		li $v0, 4
		syscall
		
		# (Float) int
		mtc1 $t2, $f1
		mtc1 $t3, $f2
		
		# Division
		div.s $f12, $f2, $f1
		
		# Gold Number
		li $v0, 2
		syscall
		
		# /n
		la $a0, ln
		li $v0, 4
		syscall
		
		addi $t0, $t0, 1
		
		j loop
	saida: 	li $v0, 10	
		syscall	
