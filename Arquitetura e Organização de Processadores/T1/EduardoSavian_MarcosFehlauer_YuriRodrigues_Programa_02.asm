################################################################
# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Programa 02
# Grupo: - Eduardo Savian de Oliveira
#        - Marcos Augusto Fehlauer Pereira
#        - Yuri Rodrigues



.data
  ListaPresenca: 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF
	msgAluno: .asciiz "Aluno(0~31):"
	msgDia: .asciiz "Dia(0~15):"
	msgPresenca: .asciiz "Presenca(0/1):"
.text
main:
	addi $s0, $zero, 1 # mask = 0x00000001
	addi $s1, $zero, 0 # dia = 0
	addi $s2, $zero, 0 # aluno = 0
	addi $s3, $zero, 0 # presenca = 0

loop:
	addi $s0, $zero, 1 # mask = 0x00000001
	# ler dia
	addi $v0, $zero, 4
	la $a0, msgDia
	syscall
	addi $v0, $zero, 5
	syscall
	add $s1, $zero, $v0

	# ler aluno
	addi $v0, $zero, 4
	la $a0, msgAluno
	syscall
	addi $v0, $zero, 5
	syscall
	add $s2, $zero, $v0

	# ler presenca
	addi $v0, $zero, 4
	la $a0, msgPresenca
	syscall
	addi $v0, $zero, 5
	syscall
	add $s3, $zero, $v0

	# modificar mask
	sllv $s0, $s0, $s2 # mask = mask << aluno
	mul $s4, $s1, 4   # calcular indice do array (dia * 4)
	lw $s6, ListaPresenca($s4) # tmp = Array[idx]
	beqz $s3, falta # if presenca == 0; marcarFalta ~{tmp | mask}
	or $s6, $s6, $s0 # else marcarPresenca {tmp | mask}
	faltaReturn:
	sw $s6, ListaPresenca($s4)
	j loop

falta:
	#inverte mascara, faz AND
	nor $s0, $zero, $s0
	and $s6, $s6, $s0
	j faltaReturn
exit:
	nop
