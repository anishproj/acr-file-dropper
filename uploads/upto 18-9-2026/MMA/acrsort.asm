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

section .bss
 temp resb 1

section .text
 	global _start
_start:

rw 1,1,title,titlelen
 
 
rw 60,0,0,0
 



















