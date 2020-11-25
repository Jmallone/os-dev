#include "TextPrint.h"
#include "IDT.h"
#include "Keyboard.h"
#include "MemoryMap.h"

extern const char Test[];
extern "C" void _start(){

	ClearScreen();
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("          Blue Dog OS         \n\r", BACKGROUND_BLINKINGBLUE | FOREGROUND_WHITE);
	PrintString(Test, BACKGROUND_BLINKINGWHITE | FOREGROUND_BLUE);
	InitializeIDT();
	MainKeyBoardHandler = KeyBoardHandler;
	
	MemoryMapEntry** UsableMemoryMaps = GetUsableMemoryRegions();

	SetCursorPosition(PositionFromCoords(45,1));
	debugLog("Memory Regions: ", MemoryRegionCount, BACKGROUND_RED | FOREGROUND_WHITE);
	SetCursorPosition(PositionFromCoords(45,2));
	debugLog("Free Memory Regions: ",UsableMemoryRegionCount, BACKGROUND_BLINKINGGREEN | FOREGROUND_BLACK);

	SetCursorPosition(PositionFromCoords(45, 4));
	
	for(uint_8 i = 0; i < UsableMemoryRegionCount;i++){
		MemoryMapEntry* memMap = UsableMemoryMaps[i]; 
		PrintMemoryMap(memMap, CursorPosition);
	}

	SetCursorPosition(PositionFromCoords(0, 9));
	/*	
	*/
	return;	
}
