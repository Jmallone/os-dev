#pragma once
#include "TypeDefs.cpp"

struct MemoryMapEntry{
	uint_64 BaseAddress;
	uint_64 RegionLeght;
	uint_32 RegionType;
	uint_32 ExtendedAttributes;
};


extern uint_8 MemoryRegionCount;



