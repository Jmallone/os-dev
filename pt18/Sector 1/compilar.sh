nasm bootloader.asm -f bin -o bootloader.bin

nasm ../Sector\ 2+/ExtendedProgram.asm -f elf64 -o ExtendedProgram.o

nasm Binaries.asm -f elf64 -o Binaries.o

gcc -Ttext 0x8000 -ffreestanding -mno-red-zone -m64 -c "Kernel.cpp" -o "Kernel.o"

ld -T"link.ld" 

cat bootloader.bin kernel.bin > bootloader.flp

qemu-system-x86_64 -fda bootloader.flp
