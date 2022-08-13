segment .data
mens1 db "Digite uma Frase",10
tam1 equ $-mens1
qdd dd 1

segment .bss
mens2 resb 100
mens3 resb 100

segment .text

  global _start
  
_Start:

print:  mov edx, tam1
		mov ecx, mens1
		mov ebx, 0
		mov eax, 4
		
ler: mov edx, 100
	 mov ecx, mens2
	 mov ebx, 1
	 mov eax, 3
	 int 80h
	 
inciar: mov esi, 0
        mov [qdd], eax
        
trocar: 
		mov al, [mens2+esi]
		mov [mens3 + esi], al
		inc esi
		cmp esi,[qdd]
		jb trocar
			
mov edx, [qdd]
mov ecx, mens3
mov ebx, 0
mov eax, 4
int 80h
		  
fim: mov eax, 1
	 int 80h

