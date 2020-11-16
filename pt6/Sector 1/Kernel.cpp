
extern "C" void _start(){
	int* ptr = (int*)0xb8000; //Video Memory Addr
	*ptr = 0x50505050;
	return;	
}
