# Instrução de micumentação de dados em memómeria (load/stores)

Processador		Memoria
UC 	   	<----
ULA 		---->	
Registradores   <----

## Instrução de máquina

```Assembly
add $t0, $t1, $t2
``` 

> $t0 =  $t1 + $t2

add -> código cp

$t0, $t1, $t2 -> operadores

## Instruções load/store
lw (*l*oad *w*ord)	|	lb (*l*oad *b*yte)

sw (*s*tore *w*ord)	|	sb (*s*tore *b*yte)

### Exemplos

```Assembly
lw $t1, 0($s1)
sw $t0, 0($s0)
```

> $t1 = MP[$s1+0]

> MP[$s0+0] = $t0

$t1 -> registrador de destino
0 -> deslocamento(offset)
$s1 -> endereço base

#### Exemplo 1
```Assembly
.data
	a: .word 5
	b: .word 2
	c: .word 0

.text
	la $s0, a
	la $s1, b
	la $s2, c

	lw $t0, 0($s0)
	lw $t1, 0($s1)

	add $t2, $t0, $t1

	sw $t2, 0($s2)	
```

#### Exemplo 2

```Assembly
.data
	d: .word 1,2,3,4,5
	e: .byte 1,2,3,4,5

.text
	la $s0, d
	la $s1, e

	lw $t0, 8($s0)
	lb $t1, 2($s1)
```

> lw $t0, 8($s0) # a = d[2]

> lb $t1, 2($s1) # b = e[2]

- Dúvida
	- Se utiliza lb ao inves de lw na variavel d?
		- O processador vai na memoria e pega o valor que tiver na casa 2 do byte, sendo assim ao inves de receber o valor 3, a variavel recebera o valor 0.

```Assembly
.data
	d: .word 1,2,3,4,5
.text
	la $s0, d
	lb $t0, 2($s0)
```

#### Exemplo 3

```Assembly
.data
	a: .byte 1,2,3
	b: .word 2
	c: .byte 3
	d: .byte 5
	e: .word 7
```

> Montador(Assembly) nunca coloca dado que não seja multiplo de 4.

- Dúvida
	- O que acontece se fazer um lw em um .byte?
		- O processador sabe que o valor mais insignativo está no menor endereço.

```Assembly
.data
	x: .byte 1,2,3,4

.text
	la $s0, x
	
	lw $t0, 0($s0)
```

> lw $t1, 1($s0) # Processador abandona

> add $s0, $s0, 2 # Processador vai para 2 endereços para cima, porém não executa porque não é mutiplo de 4.

> lw $t2, -2($s0) # Processador executa devido o ponteiro estar na segunda casa.
