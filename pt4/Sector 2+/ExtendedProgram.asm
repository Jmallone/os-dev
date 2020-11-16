[org 0x7e00]

jmp EnterProtectedMode 

%include "gdt.asm"
%include "print.asm"

EnterProtectedMode:
	call EnableA20
	cli  ;Desabilita as interrupções
	lgdt [gdt_descriptor]
	mov eax, cr0
	or eax, 1
	mov cr0, eax
	jmp codeseg:StartProtectedMode

EnableA20:
	in al, 0x92
	or al, 2
	out 0x92, al
	ret

[bits 32]

StartProtectedMode:
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov [0xb8000], byte 'H'
	;mov ebp, 0x900
	jmp $

times 2048-($-$$) db 0 ; Mais ou menos 4 Setores
