%macro rw 4
	
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	syscall
	
%endmacro

%macro disp 2
	mov rbx , [%1]
	mov rcx , %2
	
%%loop:
	push rcx
	
	rol bx,4
	mov al,bl
	and al, 0Fh
	cmp al ,9
	jbe %%digit
	add al,7
	
%%digit:
	add al,30h
	mov [temp] ,al
	rw 1,1,temp,1
	pop rcx
	dec rcx
	jnz %%loop
	
%endmacro


section .data
	temp db 0
	dis dw 1234h 
	
	newline db 10
	
	arr dw 1234h,4567h,5678h
	
	n equ 3
	sum db 0
	

section .text

	global _start
_start:
	
	xor rax,rax
	mov rsi,arr
	mov rcx,n
	
add:
	add ax,[rsi]
	add rsi,2
	
	dec rcx
	jnz add
	
	mov [sum] ,ax

	disp sum,4

	rw 1,1,newline,1

	disp dis,4

	rw 60,0,0,0
	
