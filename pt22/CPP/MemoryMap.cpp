#include "MemoryMap.h"

uint_8 UsableMemoryRegionCount;

MemoryMapEntry* UsableMemoryRegion[10];
void PrintMemoryMap(MemoryMapEntry* memoryMap, uint_16 position){
	SetCursorPosition(position);
	
	debugLog("Memory Base: ", memoryMap->BaseAddress);
	SetCursorPosition(position+80);
	debugLog("Region Length: ", memoryMap->RegionLenght);
	SetCursorPosition(position+160);
	debugLog("Memory Type: ", memoryMap->RegionType);
	SetCursorPosition(position+240);
	PrintString("Memory Attr: "); PrintString(HexToString(memoryMap->ExtendedAttributes));
	SetCursorPosition(position+400);
	//debugLog("Memory Attr: ", memoryMap->ExtendedAttributes);
}

bool MemoryRegionsGot = false;

MemoryMapEntry** GetUsableMemoryRegions(){
	
	if(MemoryRegionsGot){
		return UsableMemoryRegion;
	}

	uint_8 UsableRegionIndex;
	for (uint_8 i = 0; i < MemoryRegionCount; i++){
		MemoryMapEntry* memMap = (MemoryMapEntry*)0x5000;
		memMap += i;
		if (memMap->RegionType == 1){
			UsableMemoryRegion[UsableRegionIndex] = memMap;	
			UsableRegionIndex++;
		}
	}

	UsableMemoryRegionCount = UsableRegionIndex;
	MemoryRegionsGot = true;
	return UsableMemoryRegion;
}
