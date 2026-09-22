%macro rw 4
    mov rax, %1          
    mov rdi, %2          
    mov rsi, %3        
    mov rdx, %4        
    syscall
%endmacro


section .data
    arr db 10h, 08h, 11h, 03h, 02h, 05h
    cnt dw 6
    space db ' '
    newline db 10
    

section .bss
    buf resb 2


section .text
    global _start

_start:
    movzx ecx, word [cnt]      
    dec ecx            

outer_loop:
    mov rsi, arr  
    mov edx, ecx        
    push rcx    

inner_loop:
    mov al, [rsi]        
    cmp al, [rsi+1]      
    jbe no_swap    
    xchg al, [rsi+1]    
    mov [rsi], al        

no_swap:
    inc rsi          
    dec edx              
    jnz inner_loop      

    pop rcx    
    loop outer_loop    

    mov rbx, arr
    movzx ecx, word [cnt]

print_loop:
    push rcx
    push rbx

    mov al, [rbx]      
   
    mov ah, al
    shr ah, 4
    cmp ah, 9
    jbe adj_high
    add ah, 7
adj_high:
    add ah, 30h
    mov [buf], ah

    and al, 0Fh
    cmp al, 9
    jbe adj_low
    add al, 7
adj_low:
    add al, 30h
    mov [buf+1], al

    rw 1,1,buf, 2
    rw 1,1,space, 1

    pop rbx
    pop rcx
    inc rbx
    loop print_loop

    rw 1,1,newline, 1

rw 60,0,0,0
