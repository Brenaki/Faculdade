.data
	d: .word 1,2,3,4,5
	e: .byte 1,2,3,4,5

.text
	la $s0, d
	la $s1, e

	lw $t0, 8($s0)
	lb $t1, 2($s1)