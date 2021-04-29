global	ft_strcmp
section	.text

ft_strcmp:
	xor rax, rax	; initialize rax at 0
	xor rcx, rcx	; initialize rcx at 0

loop:
	mov bl, [rdi]	; move the value of rdi in the string in bl
	mov al, [rsi]	; move the value of rsi in the string in al
	inc rdi		; increment rdi
	inc rsi		; increment rsi

compare:
	cmp bl, 0	; compare bl with \0
	je overflow	; if bl is equal to \0, go to overflow
	cmp al, bl	; compare the value in al with the value in bl
	je loop		; if equal, start loop again
	jne overflow	; if not, go to overflow

overflow:
	sub al, bl	; substract al with bl
	jnc return	; if no substraction overflow, go to return
	mov cl, 255	; if substraction overflow, move 255 in cl (255 is the max value in 8 bit)
	sub cl, al	; substract cl with al
	mov al, cl	; and finally move cl in al
	inc rax		; increment rax
	ret		; exit return

return:
	neg rax		; rax *= -1
	ret		; exit return
