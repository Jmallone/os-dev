#pragma once
#include "TypeDefs.h"
#include "TextPrint.h"

struct MemoryMapEntry{
	uint_64 BaseAddress;
	uint_64 RegionLenght;
	uint_32 RegionType;
	uint_32 ExtendedAttributes;
};


extern uint_8 MemoryRegionCount;
extern uint_8 UsableMemoryRegionCount;


void PrintMemoryMap(MemoryMapEntry* memoryMap, uint_16 position);
MemoryMapEntry** GetUsableMemoryRegions();
