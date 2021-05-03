global	ft_read
section	.text

extern __errno_location

ft_read:
	xor rax, rax		; initialize rax at 0 for syscall
	syscall
	cmp  rax, 0		; check if syscall return value is below 0
	jl   error		; if yes, go to error
	ret			; if not, return the value of rax

error:
	neg  rax		; rax *= -1
	push rax		; save rax on the stack
	call __errno_location	; call errno
	pop  qword [rax]	; retrieve the value of rax
	mov  rax, -1		; set rax equal to -1
	ret			; exit return
