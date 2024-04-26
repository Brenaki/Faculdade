.data 
	peso: .float 120
	altura: .float 1.80
	imc: .float 0.0
	limite: .float 29.9
	obesidade1: .float 34.9
	obesidade2: .float 39.9
	msg1: .asciiz "O seu imc e igual a: "
	msg2: .asciiz "\nAtencao! Seu IMC indica que voce esta com obesidade"
	msg3: .asciiz " de grau I"
	msg4: .asciiz " de grau II"
.text
.globl main
	main: 
		la $s0, peso
		la $s1, altura
		la $s2, imc
		la $s3, limite
		la $s4, obesidade1
		la $s5, obesidade2
		
		lwc1 $f0, 0($s0)
		lwc1 $f1, 0($s1)
		lwc1 $f4, 0($s3)
		lwc1 $f5, 0($s4)
		lwc1 $f6, 0($s5)
		
		
		mul.s $f2, $f1, $f1
		div.s $f12, $f0, $f2
		swc1 $f12, 0($s2)
		#fim do calculo do ICMC
		
		
		#imprime Mensagem e valor IMC
		li $v0, 4
		la $a0, msg1
		syscall
	
		li $v0, 2
		syscall
		
		
		# comparações para verificar se há obesidade
		c.lt.s $f12, $f4
		bc1t saida
		
		c.lt.s $f12, $f5
		bc1t grau1
		bc1f grau2
		
	
	grau1:
		li $v0, 4
		la $a0, msg2
		syscall
		
		li $v0, 4
		la $a0, msg3
		syscall
		j saida
	
	grau2:
		li $v0, 4
		la $a0, msg2
		syscall
		
		li $v0, 4
		la $a0, msg4
		syscall
	
	saida:
		li $v0, 10
		syscall
