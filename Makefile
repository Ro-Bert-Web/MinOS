c       := $(shell find -type f -name "*.c")
cToAsm  := $(c:.c=.s)
asm     := $(shell echo $(cToAsm) $(shell find -type f -name "*.s") | xargs -n1 | sort -u | xargs)
obj     := $(cToAsm:.s=.o)


all: kernel7.elf ;

kernel7.elf: linker.ld start.o main.o
	arm-none-eabi-gcc -T linker.ld -o kernel7.elf start.o main.o -ffreestanding -nostdlib -lgcc

start.o: asm/start.s
	arm-none-eabi-as -o start.o asm/start.s

main.o: main.s
	arm-none-eabi-as -o main.o main.s
main.s: c/main.c
	arm-none-eabi-gcc -S -o main.s c/main.c -I ./include


install: all
	mkdir install || rm -rf install/*
	cp -r dependencies/* install
	arm-none-eabi-objcopy kernel7.elf -O binary install/kernel7.img
	test $(shell ls /media/isaiah | wc -l) -eq 1 && cp -r install/* /media/isaiah/* && umount /media/isaiah/* || echo "Please plug in exactly one drive"

.PHONY: clean
clean:
	rm -rf *.s *.o *.elf install
