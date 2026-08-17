section .text
	global ft_strcpy

ft_strcpy:
	mov	rax, rad;

.copy:
	mov	dl, byte[rsi]
	mov byte[rdi], dl

	cmp dl, 0
	je	.end

	inc rsi
	inc rdi
	jmp .copy

.end:
	ret