.data
	rgb: .word 0xFFAA00, 0xA8A628, 0xB07609
	g: .word 0,0,0
.text
	la $s0, rgb
	
	li $t7, 0x00FF00 # máscara
	
	lw $t0, 0($s0) # $t0 <- 0xFFAA00
	lw $t1, 4($s0) # $t1 <- 0xA8A628
	lw $t2, 8($s0) # $t2 <- 0xB07E09
	
	# Operações c/ a máscara
	and $t0, $t7, $t0 # $t0 <- 0x00AA00
	and $t1, $t7, $t1 # $t1 <- 0x00A600
	and $t2, $t7, $t2 # $t2 <- 0x007600
	
	# Deslocamento
	srl $t0, $t0, 8 #$t0 <- 0x0000AA
	srl $t1, $t1, 8 #$t1 <- 0x0000A6
	srl $t2, $t2, 8 #$t2 <- 0x000076
	
	# Atualização do vetor G
	la $s1, g
	sw $t0, 0($s1)
	sw $t1, 4($s1)
	sw $t2, 8($s1)