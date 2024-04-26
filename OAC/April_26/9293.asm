.data
	peso: .float 64.4
	altura: .float 1.77
	imc: .float 0.0
	limite: .float 29.9
	msg1: .asciiz "O seu imc é: "
	msg2: .asciiz "\nAtenção! Seu IMC indica obsidade"
	
.text
.globl main
	main:
		la $s0, peso
		la $s1, altura
		la $s2, imc
		la $s3, limite
		
		lwc1 $f0, 0($s0)
		lwc1 $f1, 0($s1)
		
		mul.s $f2, $f1, $f1
		div.s $f12, $f0, $f2
		
		swc1 $f12, 0($s2)
		
		li $v0,4
		la $a0, msg1
		syscall
		
		li $v0,2 # $f12 armazena o IMC
		syscall
		
		lwc1 $f3, 0($s3)
		
		c.lt.s $f12, $f3 
		bc1t saida # saida se imc < limite
			li $v0,4
			la $a0, msg2
			syscall
			
		saida: 	li $v0, 10 # exit
			syscall