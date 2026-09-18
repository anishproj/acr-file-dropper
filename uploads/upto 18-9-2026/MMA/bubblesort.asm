%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .data
	title db "Array sorting: bubblesort",10
	titlelen equ $-title
	
	arr db 10h, 08h, 02h, 05h, 01h
	arrlen equ 5
	space db " "           ; Clean formatting between numbers
	newline db 10          ; Clean formatting at the end

section .bss
 temp resb 1
 result resb 10

section .text
 	global _start
_start:

	rw 1,1,title,titlelen
	mov rcx , arrlen
	dec rcx 

oloop:
	push rcx
	mov rsi, 0

iloop:
	mov al , [arr+ rsi]
	mov bl , [arr+rsi+1]
	cmp al,bl
	
	jbe nswap
	
	mov [temp] , al
	mov al,bl
	mov bl , [temp]
	
	mov [arr+rsi] , al
	mov [arr+rsi+1] , bl

nswap:
	inc rsi
	dec rcx
	
	jnz iloop
	pop rcx
	loop oloop

	lea r8, [arr]        
	mov r13, 0           

element_loop:
	mov al, [r8]         
	mov ah, 00h           
	mov r12w, 4          

up: rol ax,4
	mov bx,ax
	and ax,000FH         
	cmp al,09
	jbe down
	add al,07h
	
down: add al,30h        
	mov [temp],al        
	
	
	push rax             
	push rbx             
	rw 1,1,temp,1       
	pop rbx              
	pop rax              
	
	mov ax,bx
	dec r12w             
	jnz up

	
	rw 1,1,space,1

	inc r8               
	inc r13              
	cmp r13, arrlen      
	jne element_loop     

	
	rw 1,1,newline,1

	; Exit System Call
	rw 60,0,0,0

