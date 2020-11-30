cd Assembly
nasm bootloader.asm -f bin -o ../Bin/bootloader.bin

nasm ExtendedProgram.asm -f elf64 -o ../Bin/ExtendedProgram.o

nasm Binaries.asm -f elf64 -o ../Bin/Binaries.o
cd ..
cd CPP
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel.cpp" -o "../Bin/Kernel.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "IDT.cpp" -o "../Bin/IDT.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "IO.cpp" -o "../Bin/IO.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Keyboard.cpp" -o "../Bin/Keyboard.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "MemoryMap.cpp" -o "../Bin/MemoryMap.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "TextPrint.cpp" -o "../Bin/TextPrint.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Heap.cpp" -o "../Bin/Heap.o"
gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Memory.cpp" -o "../Bin/Memory.o"
cd ..

cd Bin

ld -T"link.ld" 
cat bootloader.bin kernel.bin > bootloader.flp

qemu-system-x86_64 -fda bootloader.flp
