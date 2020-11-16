[org 0x7c00]

mov bp, 0x7c00 ; Começa aqui
mov sp, bp		;memoria atual

mov bx, TestString
call PrintString
jmp $

PrintString:
	mov ah, 0x0e
	.Loop:
		cmp [bx], byte 0 ; Se Bx for igual a zero Saio da Condicional
	je .Exit
		mov al, [bx]
		int 0x10 ;interuption de video
		inc bx ; bx eh o endereço e [bx] o conteudo
		jmp .Loop
	.Exit:
    	ret 

TestString:
    db 'This is a test string',0 ;declare bytes

times 510-($-$$) db 0

dw 0xAA55
