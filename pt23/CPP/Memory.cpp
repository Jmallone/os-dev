#include "Memory.h"

void memset(void* start, uint_64 value, uint_64 num){
	
	if(num<= 8){
		uint_8* valPtr = (uint_8*)&value;
		for( uint_8* ptr = (uint_8*)start; ptr < (uint_8*)((uint_64)start + num); ptr++ ){
			*ptr = *valPtr;
			valPtr++;
		}
		return;
	}

	uint_64	proceedingBytes = num % 8;
	uint_64 newNum = num - proceedingBytes;

	for(uint_64* ptr = (uint_64*)start; ptr < (uint_64*)((uint_64)start + newNum; ptr++ )){
		*ptr = *value;	
	}

	uint_8* valPtr = (uint_8*)&value;

	for(uint_8* ptr = (uint_8*)((uint_64)start + valPtr);  ptr < (uint_8*)((uint_64)start + num); ptr++){
		*ptr = *valPtr;
		valPtr++;
	}
}
