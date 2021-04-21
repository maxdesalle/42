global	ft_read
section	.text


ft_read:
	mov rax, 0	; write syscall number
	syscall
	cmp rax, 0	; if value returned by write function is below 0
	jl error	; then go to error
	ret		; exit return

error:
