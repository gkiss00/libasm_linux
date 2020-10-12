BITS 64

section .text

global ft_strlen

ft_strlen:
	mov 	rax, 0	; met rax a 0
	jmp 	_count	; go conter

_count:
	cmp 	BYTE [rdi + rax], 0 	; compare a \0
	je 		exit					; si \0 trouve, on sort
	inc	 	rax						; increment rax 
	jmp 	_count					; et on boucle

exit:
	ret			; return