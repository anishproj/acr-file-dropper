%macro rw 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .data
	title_msg   db "=== String Operations ALP ===", 10
	title_len   equ $-title_msg

	str1        db "hello world, hello assembly, hello world!", 0
	len1        equ $-str1 - 1
	str2        db "hello", 0
	len2        equ $-str2 - 1
	str3        db " - NASM 64bit", 0
	len3        equ $-str3 - 1

	msg_concat  db 10, "1. Concatenated String: "
	len_concat  equ $-msg_concat

	msg_sub     db 10, "2. Substring Search ('hello'): "
	len_sub     equ $-msg_sub

	msg_found   db " Found! Count = "
	count_place db 0, 10                   ; Injected dynamic count slot + newline
	len_found   equ $-msg_found

	msg_not     db " Not Found!", 10
	len_not     equ $-msg_not

section .bss
	result_str  resb 100

section .text
	global _start

_start:
	rw 1, 1, title_msg, title_len

	; === OPERATION 1: Concatenation (str1 + str3) ===
	cld
	mov rsi, str1
	mov rdi, result_str
	mov rcx, len1
	rep movsb                              ; Copy str1

	mov rsi, str3
	mov rcx, len3
	rep movsb                              ; Append str3

	rw 1, 1, msg_concat, len_concat
	rw 1, 1, result_str, len1 + len3       ; Direct length calculation
	rw 1, 1, title_msg + title_len - 1, 1  ; Reused existing trailing newline

	; === OPERATION 2: Substring Count (str2 in str1) ===
	rw 1, 1, msg_sub, len_sub

	mov rsi, str1
	xor ebx, ebx                           ; Match counter (R12 -> EBX)
	mov r13, len1

	cmp r13, len2
	jb .not_found
	sub r13, len2
	inc r13

.search_loop:
	push rsi
	mov rdi, str2
	mov rcx, len2
	repe cmpsb
	jne .no_match
	inc ebx                                ; Match! Increment count

.no_match:
	pop rsi
	inc rsi
	dec r13
	jnz .search_loop

	cmp ebx, 0
	je .not_found

	; Output count by modifying data segment inline
	add bl, '0'
	mov [count_place], bl                  ; Place count directly into message
	rw 1, 1, msg_found, len_found
	jmp .exit

.not_found:
	rw 1, 1, msg_not, len_not

.exit:
	rw 60, 0, 0, 0                         ; Clean exit

