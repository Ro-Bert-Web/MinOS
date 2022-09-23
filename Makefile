c       := $(shell find -type f -name "*.c")
cObj    := $(c:.c=.o)
asm     := $(shell find -type f -name "*.s")
asmObj  := $(asm:.s=.o)
obj     := $(shell echo $(cObj) $(asmObj) | xargs -n1 | sort -u | xargs)



all: kernel7.elf ;


kernel7.elf: linker.ld $(asmObj) cFiles
	arm-none-eabi-gcc -T linker.ld -o kernel7.elf $(obj) -ffreestanding -nostdlib -lgcc

cFiles:
	@cd c && make

start.o: start.s
	arm-none-eabi-as -o start.o start.s


install: all
	mkdir install || rm -rf install/*
	cp -r dependencies/* install
	arm-none-eabi-objcopy kernel7.elf -O binary install/kernel7.img
	test $(shell ls /media/isaiah | wc -l) -eq 1 && cp -r install/* /media/isaiah/* && umount /media/isaiah/* || echo "Please plug in exactly one drive"

.PHONY: clean
clean:
	cd c && make clean
	rm -rf $(obj) *.elf install
