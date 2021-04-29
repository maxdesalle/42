global	ft_read
section	.text

extern __errno_location

ft_read:
	xor rax, rax
	syscall
	cmp  rax, 0
	jl   error
	ret

error:
	neg  rax
	push rax
	call __errno_location
	pop  qword [rax]
	mov  rax, -1
	ret
