global	ft_strcpy
section	.text

ft_strcpy:
	xor rax, rax			; initialize rax at 0 (like i = 0)

loop:
	mov cl, [rsi + rax]		; move the pointed character of src in cl
	mov [rdi + rax], cl		; move the character in cl into the dst string
	cmp byte [rdi + rax], 0		; check if the end of the string has been reached
	je return			; if yes, go to return
	inc rax				; if no, increment rax (i++)
	jmp loop			; start the loop again

return:
	mov rax, rdi			; move dst into rax given rax is what's being returned
	ret				; exit return
