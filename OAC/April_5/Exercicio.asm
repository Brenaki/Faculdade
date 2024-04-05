.data
	x: .word 0,1,12,3,5,8,15,2,1
	maior: .word 0

.text
.globl main
	
	main:
		la $s0, x
		la $s1, maior
		
		add $a0, $zero, $zero
		loop: 	slti $t2, $t0, 9
			beq $t2, $zero, saida
			
			sll $t2, $t0, 2
			add $t2, $t2, $s0
			lw $t3, 0($t2)
			
			slt $t4, $t3, $a0
			beq $t4, $zero, m1
			j c1

			m1: add $a0, $zero, $t3

			c1: addi $t0, $t0, 1
			j loop

		saida:
			sw $a0, 0($s1)
