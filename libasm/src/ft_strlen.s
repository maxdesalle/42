global	ft_strlen

section .text

ft_strlen:
	xor rax, rax			; i = 0
	jmp compare			; go to compare

increment:
	inc rax				; i++

compare:
	cmp BYTE [rdi + rax], 0		; is str[i] == '\0' ?
	jne increment			; if not, go to increment
	ret				; exit return
