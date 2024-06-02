.data
	ln: .asciiz "\n"

.text
main:	li $t2, 0 # int a = 0;
	li $t3, 1 # int b = 1;
	
	add $t0, $zero, $zero # int i = 0;
	
	loop:	slti $t1, $t0, 20 # i < 20
		beq $t1, $zero, saida # false == i < 20 -> go to saida
		
		# Fibonacci
		add $t4, $t2, $t3 # aux = a + b;
		move $t2, $t3 # a = b;
		move $t3, $t4 # b = aux;
		
		# printf("%d", b);
		move $a0, $t3
		li $v0, 1
		syscall
		
		# printf("\n");
		la $a0, ln
		li $v0, 4
		syscall
		
		# i++
		addi $t0, $t0, 1
		
		j loop # go to loop
		
	saida: 	li $v0, 10	# return 0;
		syscall	