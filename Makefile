all: kernel7.elf ;

kernel7.elf: linker.ld start.o
	arm-none-eabi-gcc -T linker.ld -o kernel7.elf start.o -ffreestanding -nostdlib -lgcc

start.o: start.s
	arm-none-eabi-as -o start.o start.s


install: all
	mkdir install
	cp -r dependencies/* install
	arm-none-eabi-objcopy kernel7.elf -O binary install/kernel7.img
	test $(shell ls /media/isaiah | wc -l) -eq 1 && cp -r install/* /media/isaiah/* || echo "Please plug in exactly one drive"

.PHONY: clean
clean:
	rm -rf *.o *.elf install
