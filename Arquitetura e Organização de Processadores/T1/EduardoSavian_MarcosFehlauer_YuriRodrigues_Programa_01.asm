################################################################
# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Programa 01
# Grupo: - Eduardo Savian de Oliveira
#        - Marcos Augusto Fehlauer Pereira
#        - Yuri Rodrigues


.data
	ArrA: .word 0,0,0,0,0,0,0,0
	ArrB: .word 0,0,0,0,0,0,0,0
	msgLimite: .asciiz "Tamanho do vetor (1~8): "
	msgA: .asciiz "A["
	msgB: .asciiz "B["
	msgSwitch: .asciiz "Trocando A e B!\n"
	msgWarn: .asciiz "Valor invalido\n"
	newline: .asciiz "\n"
	cb_str: .asciiz "] = "

.text

main:
	addi $s4, $zero, 1 	# limite = 1
	la $a0, msgLimite   # prompt
	addi $v0, $zero 4
	syscall
	addi $v0, $zero, 5  # syscall read integer
	syscall
	add $s4, $zero, $v0 # limite = <valor do usuario>
	# avisar se o limite for invalido
  bgt $s4, 8, warn
  blt $s4, 1, warn
	# Ler A
	j readA
	returnA:
	# Ler B
	j readB
	returnB:
	# Trocar
	j switchAB
	returnSwitchAB:
	# Imprimir
	j printAB
	returnPrintAB:
	j exit 			# fim do programa

# Ler array A
readA:
	addi $s0, $zero, 0 	# i = 0

loopReadA:
	mul $s1, $s0, 4		# indice do array
	# prompt do usuario
	addi $v0, $zero, 4  # imprimir A[
	la $a0, msgA
	syscall
	add $a0, $zero, $s0 # imprime indice
	addi $v0, $zero, 1
	syscall
	addi $v0, $zero, 4 # imprimir ] =
	la $a0, cb_str
	syscall
	# ler valor
	addi $v0, $zero, 5  # syscall read integer
	syscall
	sw $v0, ArrA($s1)	# A[idx] = int lido
	addi $s0, $s0, 1 	# i++
	blt $s0, $s4, loopReadA 	# loop while i < $s4

	j returnA
# ---

# Ler array B
readB:
	addi $s0, $zero, 0 	# i = 0
loopReadB:
	mul $s1, $s0, 4		# indice do array
	# prompt do usuario
	addi $v0, $zero, 4  # imprimir B[
	la $a0, msgB
	syscall
	add $a0, $zero, $s0 # imprime indice
	addi $v0, $zero, 1
	syscall
	addi $v0, $zero, 4 # imprimir ] =
	la $a0, cb_str
	syscall
	# ler numero
	addi $v0, $zero, 5  # syscall read integer
	syscall
	sw $v0, ArrB($s1)	# B[idx] = int lido
	addi $s0, $s0, 1 	# i++
	blt $s0, $s4, loopReadB 	# loop while i < $s4
exitReadB:
	j returnB
# ---

# Trocar elementos de A e B
switchAB:
	addi $v0, $zero, 4  # imprimir B[
	la $a0, msgSwitch # anunciar troca
	syscall
	addi $s0, $zero, 0 		# i = 0
loopSwitchAB:
	mul $s1, $s0, 4			# indice do array
	lw $s2, ArrA($s1) 		# tmp = A[idx]
	lw $s3, ArrB($s1) 		# tmp2 = B[idx]
	sw $s3, ArrA($s1)		# A[idx] = tmp2
	sw $s2, ArrB($s1)		# B[idx] = tmp

	addi $s0, $s0, 1 		# i++
	blt $s0, $s4, loopSwitchAB 	# loop while i < $s4

	j returnSwitchAB
# ---

# Imprimir A e B
printAB:
	# imprimir A
	addi $s0, $zero, 0 		# i = 0
	j LA
	LAret:

	# imprimir B
	addi $s0, $zero, 0 		# i = 0
	j LB
	LBret:

	j returnPrintAB

LA:
	mul $s1, $s0, 4		# indice do array
	addi $v0, $zero, 4  # imprimir A[
	la $a0, msgA
	syscall
	add $a0, $zero, $s0 # imprime indice
	addi $v0, $zero, 1
	syscall
	addi $v0, $zero, 4 # imprimir ] =
	la $a0, cb_str
	syscall
	lw $a0, ArrA($s1)	# a = A[idx]
	addi $v0, $zero, 1  # print(a)
	syscall

	la $a0, newline
	addi $v0, $zero 4
	syscall

	addi $s0, $s0, 1 	# i++
	blt $s0, $s4, LA 		# loop while i < $s4
	j LAret
LB:
	mul $s1, $s0, 4		# indice do array
	addi $v0, $zero, 4  # imprimir B[
	la $a0, msgB
	syscall
	add $a0, $zero, $s0 # imprime indice
	addi $v0, $zero, 1
	syscall
	addi $v0, $zero, 4 # imprimir ] =
	la $a0, cb_str
	syscall
	lw $a0, ArrB($s1)	# a = B[idx]
	addi $v0, $zero, 1  # print(a)
	syscall

	la $a0, newline   # nova linha
	addi $v0, $zero 4
	syscall

	addi $s0, $s0, 1 	# i++
	blt $s0, $s4, LB 		# loop while i < $s4
	j LBret
# ---

# aviso
warn:
	la $a0, msgWarn   # imprimir aviso
	addi $v0, $zero 4
	syscall
	j main
# ---

exit:
	nop
