#include "Keyboard.h"

bool LeftShiftPressed = false;
uint_8 LastScanCode;

void StandardKeyboardHandler(uint_8 scanCode, uint_8 chr){
	if(chr != 0){
		switch (LeftShiftPressed){ 
			case true:
				switch(scanCode){
					case 0x0D:
						PrintChar('+');
					break;
					case 0x0B:
						PrintChar('?');
					break;

				default:
						PrintChar(chr - 32);
				}
			break;

			case false:
				PrintChar(chr);
			break;

		}
	}else{ 
		switch(scanCode){
			case 0x8E: //BackSpace
				SetCursorPosition(CursorPosition - 1);
				PrintChar(' ');
				SetCursorPosition(CursorPosition - 1);
			break;

			case 0x2A: // Left Shift
				LeftShiftPressed = true;
			break;
			
			case 0xAA: // Left Shift Released
				LeftShiftPressed = false;
			break;

			case 0x9C: // Enter
				PrintString("\n\r");
			break;
			
			case 0x53: // Delete Pressed
				PrintString("Deletado meu Cumpadi!");
			break;

		}
	}
}

void KeyBoardHandler0xE0(uint_8 scanCode){
	switch(scanCode){
		case 0x50: //Down Arrow
			SetCursorPosition(CursorPosition + VGA_WIDTH);
		break;
		case 0x48: //Up arrow
			SetCursorPosition(CursorPosition - VGA_WIDTH);
		break;
		case 0x4B: //left arrow
			SetCursorPosition(CursorPosition - 1);
		break;
		case 0x4D: //righ arrow
			SetCursorPosition(CursorPosition + 1);
		break;


	}	
}

void KeyBoardHandler(uint_8 scanCode, uint_8 chr){
	
	switch(LastScanCode){
		case 0xE0:
			KeyBoardHandler0xE0(scanCode);
		break;
		default:
			StandardKeyboardHandler(scanCode, chr);
	}	
	LastScanCode = scanCode;
	
}

