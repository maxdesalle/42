global	ft_write

section	.text

ft_write:
	mov rax, 1	; write syscall number
	syscall
	cmp rax, 0	; if value returned by write function is below 0
	jl error	; then go to error
	ret		; exit return

error:
	
