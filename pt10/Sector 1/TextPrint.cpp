#pragma once
#include "TextModeColorCodes.cpp"
#include "TypeDefs.cpp"
#include "IO.cpp"

#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition; 
uint_8 CountScreenClear;

void ClearScreen(uint_64 ClearColor = BACKGROUND_BLACK | FOREGROUND_WHITE){
	CountScreenClear = 0;
	uint_64 value = 0;
	value += ClearColor << 8;
	value += ClearColor << 24;
	value += ClearColor << 40;
	value += ClearColor << 56;
	for (uint_64* i = (uint_64*)VGA_MEMORY; i < (uint_64*)(VGA_MEMORY + 40000); i++){
		*i = value;	
		CountScreenClear++;
	}
}

// Position is a index for 0 to the end of video memory
void SetCursorPosition(uint_16 position){
	
	outb(0x3D4, 0x0F);	
	outb(0x3D5, (uint_8)(position & 0XFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, ((uint_8)(position >> 8) & 0xFF));
	CursorPosition = position;
	
	if(CursorPosition > 2000) CursorPosition = 2000;

	if(CursorPosition < 0) CursorPosition = 0;

	
}

uint_16 PositionFromCoords(uint_8 x, uint_8 y){

	return y * VGA_WIDTH + x;	
}

/* Função para Imprimir Caracteres*/
void PrintString(const char* str, uint_8 color = BACKGROUND_BLACK | FOREGROUND_WHITE){
	uint_8* charPtr = (uint_8*)str;
	uint_16 index = CursorPosition;
	while(*charPtr != 0){
		
		switch(*charPtr){
			case 10:
				index += VGA_WIDTH;
			break;
			case 13:
				index -= index % VGA_WIDTH;
			break;
		default:

			*(VGA_MEMORY + index * 2 ) = *charPtr;
			*(VGA_MEMORY + index * 2 + 1 ) = color;

			index++;
		}

		charPtr++;	
	}
	SetCursorPosition(index);
}

/* Função para imprimir numeros*/

char hexToStringOutput[128]; //Buffer
template<typename T>

const char* HexToString(T value){

	T* valPtr = &value;
	uint_8* ptr;
	uint_8 temp;
	uint_8 size = (sizeof(T)) * 2 - 1;
	uint_8 i;
	
	for(i = 0; i < size; i++){
		
		ptr = ((uint_8*)valPtr + i);
		temp = ((*ptr & 0xF0) >> 4);
		hexToStringOutput[size - (i*2+1)] = temp + (temp > 9 ? 55 : 48);

		temp = ((*ptr & 0x0F));
		hexToStringOutput[size - (i*2+0)] = temp + (temp > 9 ? 55 : 48);
	}

	hexToStringOutput[size + 1] = 0;

	return hexToStringOutput;	
}
