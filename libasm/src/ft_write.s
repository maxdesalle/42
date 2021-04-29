global	ft_write
section	.text

extern __errno_location

ft_write:
	mov rax, 1		; write syscall number
	syscall
	cmp rax, 0		; if value returned by write function is below 0
	jl error		; then go to error
	ret			; exit return

error:
	neg rax
	push rax		; save rax on the stack
	call __errno_location	; call the error function
	pop qword [rax]		; retrieve the rax value from the stack
	mov rax, -1		; set rax equal to -1
	ret			; exit return;
