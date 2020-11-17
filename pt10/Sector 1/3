#include "TextPrint.cpp"

extern "C" void _start(){

	SetCursorPosition(PositionFromCoords(0, 0));
	
	PrintString("Blue Dog OS");
	//PrintString("Hello World\n\rThis is a New Line!\n\r", BACKGROUND_RED | FOREGROUND_CYAN );
	
	//PrintString("Testando 1!\n\r", BACKGROUND_BLINKINGRED | FOREGROUND_CYAN );
	//PrintString("Testando 2!\n\r", BACKGROUND_BLINKINGBLUE | FOREGROUND_GREEN );
	//PrintString("Testando 3!\n\r", BACKGROUND_BLINKINGYELLOW | FOREGROUND_LIGHTGREEN );

	//PrintString(HexToString(0x1234abcd));
	//PrintString("\n\r");
	//PrintString(HexToString("HI"));

	ClearScreen();
	SetCursorPosition(PositionFromCoords(0,0));
	PrintString("Contador de pixel apagados: 0x");
	PrintString(HexToString(CountScreenClear));

	return;	
}
