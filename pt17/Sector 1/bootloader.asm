[org 0x7c00]
mov [BOOT_DISK], dl
mov bp, 0x7c00 ; Começa aqui
mov sp, bp		;memoria atual

call ReadDisk

jmp PROGRAM_SPACE 

%include "print.asm"
%include "DiscRead.asm"

times 510-($-$$) db 0

dw 0xAA55
