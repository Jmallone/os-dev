#pragma once
#include "TypeDefs.h"

/*memset:
	start: Addr Base
	value: add this value in all addr
	num: size of addr [range]  
*/

void memset(void* start, uint_64 value, uint_64 num);
