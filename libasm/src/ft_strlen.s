global	ft_strlen
section .text

ft_strlen:
	mov rax, -1		; i = -1

compare:
	inc rax			; i++
	cmp BYTE [rdi + rax], 0	; is str[i] == '\0' ?
	jne compare		; if not, start the loop again
	ret			; exit return
