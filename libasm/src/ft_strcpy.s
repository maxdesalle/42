global	ft_strcpy
section	.text

ft_strcpy:
	xor rax, rax

loop:
	mov cl, [rsi + rax]
	mov [rdi + rax], cl
	cmp byte [rdi + rax], 0
	je return
	inc rax
	jmp loop

return:
	mov rax, rdi
	ret
