PrintString:
	push ax
	push bx

	mov ah, 0x0e
	.Loop:
		cmp [bx], byte 0 ; Se Bx for igual a zero Saio da Condicional
	je .Exit
		mov al, [bx]
		int 0x10 ;interuption de video
		inc bx ; bx eh o endereço e [bx] o conteudo
		jmp .Loop
	.Exit:
		pop ax
		pop bx
    	ret 


