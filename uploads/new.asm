%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

%macro disp 2
	mov rbx, [%1]
	mov r12, %2
	
	%%loop:
	push r12
	rol bx,4
	mov al,bl
	and al,0Fh
	cmp al , 9
	jbe %%digit
	add al,7
	
	
	
	%%digit:
	add al,30h
	mov [t] , al
	rw 1,1,t,1
	pop r12
	dec r12
	jnz %%loop


%endmacro




section .data
	title db "Array sorting: bubblesort",10
	titlelen equ $-title
	
	t db 0
	
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
	mov rcx , arrlen-1
	

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

; --- DISPLAY LOOP USING YOUR MACRO ---
	mov r8, 0             ; Index pointer

element_loop:
	mov qword [elem], 0   ; Clear all 8 bytes first
	mov al, [arr + r8]
	mov [elem], al        ; Put single byte into lower position (00000000000000XXh)
	
	disp elem, 2          ; Pass memory label (%1) and digit count (%2)
	
	rw 1, 1, space, 1
	
	inc r8
	cmp r8, arrlen
	jne element_loop

	rw 1, 1, newline, 1

	; Exit
	rw 60, 0, 0, 0
	
	rw 1,1,newline,1

	; Exit System Call
	rw 60,0,0,0
