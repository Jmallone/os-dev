[org 0x7e00]

mov bx, ExtendedSpaceSuccess
call PrintString

jmp $

%include "print.asm"

ExtendedSpaceSuccess:
	db 'We Are sucesso bro!',0

times 2048-($-$$) db 0 ; Mais ou menos 4 Setores
