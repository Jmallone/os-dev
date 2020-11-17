#include "TypeDefs.cpp"
#include "IO.cpp"
#pragma once
#define VGA_MEMORY (uint_8*)0xb8000
#define VGA_WIDTH 80

uint_16 CursorPosition; 

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
