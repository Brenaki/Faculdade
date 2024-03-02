.data
	x: .byte 1,2,3,4

.text
	la $s0, x
	
	lw $t0, 0($s0)