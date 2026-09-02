;add macro
;added:
%macro rw 4
	mov rax , %1
	mov rdi , %2
	mov rsi , %3
	mov rdx , %4
%endmacro

section .data
	msg1 db "base add:",10
	msg2 db "offset: ",10
	msg3 db "GDTR:",10

	m1 equ $-msg1
	m2 equ $-msg2
	m3 equ $-msg3


section .bss	

	abc resq 1 				; quad word 64 bits
	abclim resw 1
	temp64 resq 1
	temp16 resw 1
	asc resb 1

	
section .text
	 global _start	
_start:
	
	rw 1,1,msg3,m3
	rw 1,1,msg1,m1
	
	mov rsi, abc
	sgdt [rsi] ;Store GDTR contents into RSI destination: 8 bytes, operand: 8+2 bytes
	
	mov rax, [rsi]
	call display16				;call display64/ display16  ;UNCOMMENT LATER
	
	rw 1,1,10,1 ;for newline
	
	rw 1,1,msg2,m2
	
	mov rsi,abclim 			; point rsi to gdt limit
	
	mov ax, [rsi]
	
	;call display16 		;UNCOMMENT later
	
	
	
	rw 60,0,0,0
	
					;write after the exit code: function to display 64 bit cause its a callable func not a macro

	display16:
		
		mov bp , 4 ;set coutner for 4 digit number  = 16 bits, 16 for 64bit dipaly. for 64 bit: mov bp,16
	again2:
		rol ax,4  		;16 bit use ax for 64 bit display use RAX everwhere instead  of AX
		mov [temp16] , ax 	;for 64 bit use temp64 for 16 bits use temp16 (depends on variable name)
		and ax, 0Fh 		;16 bit: Ax, 64 bit : RAX
		cmp al, 09h 		;al as-is for any type
		
		jbe skip16
		add al,07h
		
	skip16:
	
		add al, 30h
		mov [asc] , al
	
	rw 1,1,asc,1
	mov ax , [rsi]
	dec bp
	jnz again2
	ret 				;VERY IMPORTANT: NEEDED TO MARK END OF FUNCTION
		
		
		
		
		
	
	

