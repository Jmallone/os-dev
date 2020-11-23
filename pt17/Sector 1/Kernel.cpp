#include "TextPrint.cpp"
#include "IDT.cpp"
#include "Keyboard.cpp"
#include "MemoryMap.cpp"

extern const char Test[];
extern "C" void _start(){

	ClearScreen();
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("          Blue Dog OS         \n\r", BACKGROUND_BLINKINGBLUE | FOREGROUND_WHITE);
	PrintString(Test, BACKGROUND_BLINKINGWHITE | FOREGROUND_BLUE);
	InitializeIDT();
	MainKeyBoardHandler = KeyBoardHandler;
	

	SetCursorPosition(PositionFromCoords(45,1));
	debugLog("Free Memory Regions: ", MemoryRegionCount, BACKGROUND_RED | FOREGROUND_WHITE);

	SetCursorPosition(PositionFromCoords(0,9));

	return;	
}
