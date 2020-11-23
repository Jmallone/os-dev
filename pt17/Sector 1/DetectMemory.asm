
MemoryRegionCount:
	db 0
	GLOBAL MemoryRegionCount

DetectMemory:
	mov ax, 0
	mov es, ax
	mov di, 0x5000 		; Numero Arbitrario
	mov edx, 0x534D4150 ; Magic Number
	xor ebx, ebx

	.repeat:
		mov eax, 0xE820 ; 
		mov ecx, 24 ; size for Memory Table Listen 
		int 0x15 ; Bios Interrupt
		
		cmp ebx, 0
		je .finish
		
		add di, 24
		inc byte [MemoryRegionCount]
		jmp .repeat

	.finish:
	ret
