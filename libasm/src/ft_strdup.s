global	ft_strdup
section	.text

extern __errno_location
extern ft_strlen
extern ft_strcpy
extern malloc

ft_strdup:
	cmp rdi, 0		; check if the given string (stored in rdi) is valid
	je return		; if not, go to return
	push rdi		; save rdi on the stack

length:
	call ft_strlen		; call the ft_strlen function
	inc rax			; increment rax so it gets equal to \0
	mov rdi, rax		; move rax into rdi given rax will be used in the following malloc

memory:
	call malloc		; call the malloc function
	cmp rax, 0		; check if malloc was valid
	je return		; if not, go to return
	mov rdi, rax		; move rax into rdi given rax will be used in the following ft_strcpy

copy:
	pop rsi			; get the rdi value back from the stack, and store it in rsi
	call ft_strcpy		; call the ft_strcpy function
	ret			; exit return

return:
	xor rax, rax		; rax == 0
	ret			; exit return
