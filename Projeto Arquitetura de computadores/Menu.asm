segment .data
	mens db "Digite uma opçao do menu: 1 - acessar; 2 - cadastrar; 3 - sair", 0xa
	tam equ $ -mens
	
	lt db 27,"[H",27,"[J"
	
segment .bss
	mens2 resb 4

segment .text
	global _start
	
_start:

mov edx, 6
mov ecx, lt
call print

mov edx,tam
mov ecx mens
call print

sair: mov eax, 1
  	int 80h

print:
 
   	mov ebx, 0
   	mov eax, 4
   	int 80h
   	ret
 	 
ler:
 	mov ebx, 1
 	mov eax, 3
 	int 80h
 	ret