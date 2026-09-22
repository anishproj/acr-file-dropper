%macro operate 4
	mov rax, %1
	mov rdi, %2
	mov rsi, %3
	mov rdx, %4
	syscall
%endmacro

section .bss
	fname1 resb 15
	fd1 resq 1
	fname2 resb 15
	fd2 resq 1
	buff resb 512
	bufflen resq 1

section .data 
	msg1 db "error" ,10
	msgl1 equ $-msg1
	msg2 db "file copied!", 10
	msgl2 equ $-msg2

section .text
	global _start:
_start:
	pop r8
	cmp r8,3
	jne err
	pop r8
	pop r8
	
	mov rsi,fname1
	
	above:
	mov al,[r8]
	cmp al,00
	je next
	mov [rsi],al
	inc r8
	inc rsi
	jmp above
	
	next:
	pop r8
	mov rsi, fname2
	
	above2:
	mov al , [r8]
	cmp al,00
	je next2
	mov [rsi],al
	inc r8
	inc rsi
	jmp above2
	
	next2:
    ; 1. Open the source file for reading
    operate 2, fname1, 000000q, 0777q  ; Syscall 2 (sys_open): opens fname1 in read-only mode (000000q)
    mov [fd1], rax                     ; Save the returned file descriptor into memory variable fd1

    ; 2. Read contents from the source file into the buffer
    operate 0, [fd1], buff, 512        ; Syscall 0 (sys_read): reads up to 512 bytes from fd1 into 'buff'
    mov [bufflen], rax                 ; Save the actual number of bytes read into bufflen

    ; 3. Create and open the destination file
    operate 85, fname2, 0777q, 0       ; Syscall 85 (sys_creat): creates the new file fname2 with 0777 permissions
    operate 2, fname2, 2, 0777q        ; Syscall 2 (sys_open): opens fname2 with read/write access (mode 2)
    mov [fd2], rax                     ; Save the destination file descriptor into memory variable fd2

    ; 4. Write the buffered data into the destination file
    operate 1, [fd2], buff, [bufflen]  ; Syscall 1 (sys_write): writes [bufflen] bytes from 'buff' into fd2

    ; 5. Close both files to free system resources
    operate 3, [fd2], 0, 0             ; Syscall 3 (sys_close): closes the destination file descriptor (fd2)
    operate 3, [fd1], 0, 0             ; Syscall 3 (sys_close): closes the source file descriptor (fd1)

    ; 6. Print the success message to the terminal
    operate 1, 1, msg2, msgl2          ; Syscall 1 (sys_write): prints msg2 ("file copied!") to stdout (fd 1)
	
	jmp end
	
	err: 
	operate 1,1,msg1,msgl1
	
	end:
	operate 60,0,0,0
	
	

	
