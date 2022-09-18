all:
	arm-none-eabi-gcc -S -o main.s main.c -I ./include
	arm-none-eabi-as -o start.o start.s
	arm-none-eabi-as -o main.o main.s
	arm-none-eabi-gcc -T linker.ld -o kernel7.elf start.o main.o -ffreestanding -nostdlib -lgcc
	arm-none-eabi-objcopy kernel7.elf -O binary install/kernel7.img
