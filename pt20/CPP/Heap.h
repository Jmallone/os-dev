#pragma once
#include "TypeDefs.h"

struct MemorySegmentHeader{
	uint_64 MemoryLenght;
	MemorySegmentHeader* NextSegment;
	MemorySegmentHeader* PreviousSegment;
	MemorySegmentHeader* NextFreeSegment;
	MemorySegmentHeader* PreviousFreeSegment;
	bool Free;
};


extern void InitializeHeap(uint_64 heapAddress, uint_64 heapLength);
extern void* malloc(uint_64 size);
