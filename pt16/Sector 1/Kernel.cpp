#include "TextPrint.cpp"
#include "IDT.cpp"
#include "Keyboard.cpp"

extern const char Test[];
extern "C" void _start(){

	ClearScreen();
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("          Blue Dog OS         \n\r", BACKGROUND_BLINKINGBLUE | FOREGROUND_RED);
	PrintString(Test, BACKGROUND_BLINKINGWHITE | FOREGROUND_BLUE);
	InitializeIDT();
	MainKeyBoardHandler = KeyBoardHandler;
	
	PrintString(IntegerToString(1996));
	PrintString("\n\r");
	PrintString(IntegerToString(-155));

	PrintString("\n\r");
	PrintString(HexToString(10));

	PrintString("\n\r");

	int a = 10;
	int b = 20;
	int c = 0;
	c = b+3*a;

	debugLog("Resultado ", c);	
	//float x = 67.56123;
	float x = -36.712345678;
	PrintString(FloatToString(x, 2));
	return;	
}
