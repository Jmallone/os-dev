
PROGRAM_SPACE equ 0x7e00

ReadDisk:

	mov ah, 0x02
	mov bx, PROGRAM_SPACE
	mov al, 64 			;Quantos setores queremos ler
	mov dl, [BOOT_DISK] ;daonde esta lendo
	mov ch, 0x00		; Cilindro 0
	mov dh, 0x00		; head 0 
	mov cl, 0x02		;Sector 2
	
	int 0x13			;Interrupção para leitura do Disco
	jc DiskReadFailed;carry flag
	ret

BOOT_DISK:
	db 0
	
DiskReadErrorString:
	db ' Disk Read Failed',0

DiskReadFailed:
	mov bx, DiskReadErrorString
	call PrintString
	
	jmp $
