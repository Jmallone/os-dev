#include "TextPrint.cpp"
#include "IDT.cpp"

extern const char Test[];
extern const char Test2[];

extern "C" void _start(){

	ClearScreen();
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("          Blue Dog OS\n\r", BACKGROUND_BLINKINGBLUE | FOREGROUND_RED);
	PrintString(Test);
	PrintString(Test2);
	InitializeIDT();


	return;	
}
