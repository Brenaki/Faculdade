# Exercícios

#### 9.1 Exercício

- Considerando os itens a seguir:

	* (1) $f0
	* (2) add.s
	* (3) sub.d
	* (4) Coprocessador 1
	* (5) cvt.s.w
	* (6) load word para o processador C1
	* (7) 32

- **preencha** as lacunas abaixo, conforme o item mais adequado:

	* (3) instrução de subtração para precisão dupla
	* (4) FPU do processador MIPS
	* (2) instrução de soma para precisão simples
	* (5) conversão de valores
	* (7) número de registradores de vírgula flutuante no C1
	* (1) registrador
	* (6) lwc1

#### 9.2 Exercício

- O índice de massa corporal (IMC) é reconhecido como padrão internacional para avaliar o grau de sobrepeso e obesidade das pessoas. O IMC é calculado dividindo a massa (em kg) pela altura (m) ao quadrado:

```
IMC = Peso/Altura²
```

- Exemplo de como calcular o IMC:

```
IMC = 80kg/1,80²m = 24,69kg/m²
```

- Complete o programa abaixo, criando um programa que informe o IMC, conforme os dados a serem obtidos no segmento de dados estáticos. O programa deve armazenar o IMC obtido na variável *imc*:

```Assembly
.data
	peso: .float 80.0
	altura: .float 1.80
	imc: .float 0.0
	msg1: .asciiz "O seu IMC e igual a: "

.text
.globl main
	main:
		la $s0, peso
		la $s1, altura
		la $s2, imc
		...
```

[Code](./9293.asm)

#### 9.3 Exercício

- Modifique o programa anterior, de forma que o programa após mostrar em tela o IMC, informe uma mensagem de aviso se o indivíduo estiver obeso (*grau I u grau II*). Para isso, complete o programa abaixo:

```Assembly
.data
	peso: .float 80.0
	altura: .float 1.80
	imc: .float 0.0
	limite: .float 29.9 # limite (sem obesidade)
	msg1: .asciiz "O seu IMC e igual a: "
	msg2: .asciiz "\nAcima do peso"

.text
.globl main
	main:
		la $s0, peso
		la $s1, altura
		la $s2, imc
		la $s3, limite
		...
```

[Code](./9293.asm)
