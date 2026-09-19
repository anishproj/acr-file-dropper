%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .data
	temp db 0
	newline db 10 
	
	gd db 10, "GDTR: "
	gdl equ $-gd
	ld db 10, "LDTR: "
	ldl equ $-ld
	id db 10, "IDTR: "
	idl equ $-id
	t db 10, "TR: "
	tl equ $-t
	ms db 10, "MSW: "
	msl equ $-ms

section .bss
	buf resb 10   ; Buffer to store descriptor table/register info

section .text
	global _start

_start:
	; --- GDTR ---
	rw 1, 1, gd, gdl
	sgdt [buf]
	mov rax, [buf]        
	call disp64

	; --- IDTR ---
	rw 1, 1, id, idl
	sidt [buf]
	mov rax, [buf]
	call disp64

	; --- LDTR ---
	rw 1, 1, ld, ldl
	sldt [buf]
	movzx rax, word [buf]
	call disp16

	; --- TR ---
	rw 1, 1, t, tl
	str [buf]
	movzx rax, word [buf]
	call disp16

	; --- MSW ---
	rw 1, 1, ms, msl
	smsw [buf]
	movzx rax, word [buf]
	call disp16

	; Print newline at the end
	rw 1, 1, newline, 1

	; Exit syscall
	rw 60, 0, 0, 0

;------- display routines -------

disp16:
	shl rax, 48           ; Restored your original shift for 16-bit registers
	mov bp, 4
	jmp loop
	
disp64:
	mov bp, 16

loop:
	rol rax, 4
	push rax
	and al, 0Fh
	cmp al, 9
	jbe digit
	add al, 7

digit:	
	add al, 30h
	mov [temp], al
	rw 1, 1, temp, 1
	
	pop rax
	dec bp
	jnz loop
	
	ret
