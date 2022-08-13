segment .data
	mens db "bom dia!",0xa
	tam equ $ -mens
segment .text
	global _start
_start:
	mov edx, tam
	mov ecx, mens
	mov ebx, 0
	mov eax, 4
	int 80h
sair: mov eax, 1
	  int 80h
