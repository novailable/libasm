BITS    64

section .text:
	global  ft_strlen

ft_strlen:
    mov     rax, rdi

.loop:
    movdqu      xmm0, [rax]
    pxor        xmm1, xmm1
    pcmpeqb     xmm0, xmm1
    pmovmskb    edx,  xmm0
    test        edx,  edx
    jnz         .found

    add         rax, 16
    jmp         .loop

.found:
    bsf edx, edx
    sub rax, rdi
    add rax, rdx
    ret
