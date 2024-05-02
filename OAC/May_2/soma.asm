.data 



	vetor: .word 2, 4, 8, 10 , 12, 16, 18

	tam: .word 7

.text



.globl main



main:



	# preparando os argumentos

	la $a0, vetor

	la $a1, tam

	lw $a1, 0($a1)



	jal soma

	



	move $a0, $v0

	li $v0, 1

	syscall

	



	li $v0, 10

	syscall







soma: 

		addi $sp, $sp, -4

		sw $ra, 0($sp)



		li $t0, 0

		li $v0, 0



		L1: 	beq $t0, $a1, fim

			sll $t1, $t0, 2

			add $t1, $t1, $a0

			lw $t1, 0($t1)

			

			add $v0, $v0, $t1

			addi $t0, $t0, 1

			j L1





		fim:

			lw $ra, 0($sp)

			addi $sp, $sp, 4

			jr $ra

