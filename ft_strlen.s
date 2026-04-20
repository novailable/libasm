;section .text
;    global ft_strlen
;
;ft_strlen:
;    xor rax, rax
;
;.loop:
;    cmp byte [rdi + rax], 0
;    je .done
;    inc rax
;    jmp .loop

;.done:
;    ret

section .text
    global ft_strlen

ft_strlen:
    mov     rax, rdi                ; keep start pointer in rax

.align_check:
    test    rdi, 7                  ; aligned to 8 bytes?
    jz      .word_loop

.byte_loop:
    cmp     byte [rdi], 0
    je      .done
    inc     rdi
    test    rdi, 7
    jnz     .byte_loop

.word_loop:
    mov     rcx, [rdi]              ; load 8 bytes
    mov     rdx, rcx

    mov     r8, 0x0101010101010101
    sub     rdx, r8

    not     rcx
    and     rdx, rcx

    mov     r8, 0x8080808080808080
    and     rdx, r8
    jnz     .found_zero

    add     rdi, 8
    jmp     .word_loop

.found_zero:
    cmp     byte [rdi], 0
    je      .done
    cmp     byte [rdi + 1], 0
    je      .done_1
    cmp     byte [rdi + 2], 0
    je      .done_2
    cmp     byte [rdi + 3], 0
    je      .done_3
    cmp     byte [rdi + 4], 0
    je      .done_4
    cmp     byte [rdi + 5], 0
    je      .done_5
    cmp     byte [rdi + 6], 0
    je      .done_6
    cmp     byte [rdi + 7], 0
    je      .done_7

.done:
    sub     rdi, rax
    mov     rax, rdi
    ret

.done_1:
    lea     rdi, [rdi + 1]
    jmp     .done
.done_2:
    lea     rdi, [rdi + 2]
    jmp     .done
.done_3:
    lea     rdi, [rdi + 3]
    jmp     .done
.done_4:
    lea     rdi, [rdi + 4]
    jmp     .done
.done_5:
    lea     rdi, [rdi + 5]
    jmp     .done
.done_6:
    lea     rdi, [rdi + 6]
    jmp     .done
.done_7:
    lea     rdi, [rdi + 7]
    jmp     .done