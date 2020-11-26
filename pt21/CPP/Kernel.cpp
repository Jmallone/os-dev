#include "TextPrint.h"
#include "IDT.h"
#include "Keyboard.h"
#include "MemoryMap.h"
#include "Heap.h"

extern const char Test[];

void InitLogo(){
	
	ClearScreen();
	SetCursorPosition(PositionFromCoords(0, 0));
	PrintString("          Blue Dog OS         \n\r", BACKGROUND_BLINKINGBLUE | FOREGROUND_WHITE);
	PrintString(Test, BACKGROUND_BLINKINGWHITE | FOREGROUND_BLUE);
	InitializeIDT();

	/*Thats is Issue, fix later*/
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

}

extern "C" void _start(){

	InitLogo();
	InitializeHeap(0x100000, 0x100000);
	void* TestMemoryAddress = malloc(0x009);
	void* TestMemoryAddress2 = malloc(0x010);
	void* TestMemoryAddress3 = malloc(0x010);

	PrintString(HexToString((uint_64)TestMemoryAddress));
	PrintString("\n\r");
	PrintString(HexToString((uint_64)TestMemoryAddress2));
	PrintString("\n\r");
	PrintString(HexToString((uint_64)TestMemoryAddress3));
	PrintString("\n\r");
	int a = 1;
	PrintString(IntegerToString((uint_8)sizeof(MemorySegmentHeader)));
	return;	
}
