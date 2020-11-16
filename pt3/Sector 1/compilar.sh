nasm bootloader.asm -f bin -o bootloader.bin
nasm ../Sector\ 2+/ExtendedProgram.asm -f bin -o ExtendedProgram.bin
cat bootloader.bin ExtendedProgram.bin > bootloader.flp
qemu-system-x86_64 bootloader.flp
