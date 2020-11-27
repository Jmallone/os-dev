
jmp EnterProtectedMode 

%include "gdt.asm"
%include "print.asm"
%include "DetectMemory.asm"

EnterProtectedMode:
	call DetectMemory
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

%include "CPUID.asm"
%include "SimplePaging.asm"

StartProtectedMode:
	mov ax, dataseg
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov [0xb8000], byte 'H'

	call DetectCPUID
	call DetectLongMode
	call SetUpIdentityPaging
	call EditGDT

	jmp codeseg:Start64Bit 

[bits 64]
[extern _start]

%include "IDT.asm"

Start64Bit:
	mov edi, 0xb8000

	;mov rax, 0x0f200f200f200f20 ; BlackScreen
	mov rax, 0x1f201f201f201f20 ; blueScreen

	mov ecx, 500 
	rep stosq
	call ActivateSSE
	call _start
	jmp $

ActivateSSE:
	mov rax, cr0
	and ax, 0b11111101
	or ax, 0b00000001
	mov cr0, rax

	mov rax, cr4
	or ax, 0b1100000000
	mov cr4, rax
	ret

times 2048-($-$$) db 0 ; Mais ou menos 4 Setores
