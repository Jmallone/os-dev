%macro IncBin 2
	SECTION .rodata
	GLOBAL %1
%1:
	incbin %2
	db 0
	;%1_size: dq 1%_size - %1
%endmacro

IncBin Test, "logo.txt"
IncBin Test2, "test.txt"
