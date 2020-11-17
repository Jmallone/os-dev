#include "TextPrint.cpp"

extern "C" void _start(){

	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("Hello World\n\rThis is a New Line!\n\r");
	PrintString(HexToString(0x1234abcd));
	PrintString("\n\r");
	PrintString(HexToString("HI"));
	return;	
}
