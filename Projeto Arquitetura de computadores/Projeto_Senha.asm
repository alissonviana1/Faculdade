;Alisson viana de andrade

segment .data
	mens db "Digite uma senha de 6 letras com formato XxXxXx: ",0xa
	tam equ $ -mens

	mens4 db "Tente acerta a senha digitada: ", 0xa
	tam4 equ $ -mens4
    
	lt db 27,"[H",27,"[J"
    
	mens6 db "Acertou!!", 0xa
	tam6 equ $-mens6
 	 
segment .bss
	mens2 resb 100
	mens5 resb 100
    
    
    
segment .text
	global _start


_start:

;fragmentos

mov edx, 6
mov ecx, lt
call print  

mov edx, tam
mov ecx, mens
call print
 
mov edx,7
mov ecx,mens2
call ler

comparar: cmp eax,7
      	jne _start
     	 
mov esi, 0
inifor: mov al, [mens2+esi]
    	cmp al, 'A'
    	jb _start
    	cmp al, 'Z'
    	ja _start
    	inc esi
    	mov al, [mens2+esi]
    	cmp al, 'a'
    	jb _start
    	cmp al, 'z'
    	ja _start   	 
    	inc esi
    	cmp esi,6
    	jne inifor

mov edx, 6
mov ecx, lt
call print  

mov edx, tam4
mov ecx, mens4
call print

mov edx, 6
mov ecx, mens5
call ler


mov esi, 0
for: mov al, [mens2+esi]
     cmp al,[mens5+esi]
     jne sair
     inc esi
     cmp esi,6
     jne for
    
mov edx, tam6
mov ecx, mens6
call print

sair: mov eax, 1
  	int 80h

;area de procedimentos
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
   	 


