global	ft_strlen

section .text

ft_strlen:
	xor rax, rax		; i = 0

compare:
	inc rax			; i++
	cmp BYTE [rdi + rax], 0	; is str[i] == '\0' ?
	jne compare		; if not, start the loop again
	ret			; exit return
