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