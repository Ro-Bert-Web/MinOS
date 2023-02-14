gnu     := aarch64-linux-gnu
c       := $(shell find -type f -name "*.c")
cObj    := $(c:.c=.o)
asm     := $(shell find -type f -name "*.s")
asmObj  := $(asm:.s=.o)
obj     := $(shell echo $(cObj) $(asmObj) | xargs -n1 | sort -u | xargs)
target  := kernel8



all: installation ;


$(target).elf: linker.ld cFiles asmFiles
	$(gnu)-ld -T linker.ld -o $(target).elf $(obj)

cFiles:
	@cd c && make

asmFiles:
	@cd asm && make

installation: $(target).elf
	mkdir install 2> /dev/null || rm -rf install/*
	cp -r dependencies/* install
	$(gnu)-objcopy $(target).elf -O binary install/$(target).img

install: installation
	@cat msg/installing
	@test $(shell ls /media/isaiah | wc -l) -eq 1 && rm /media/isaiah/*/* -r && cp -r install/* /media/isaiah/* && umount /media/isaiah/* && cat msg/install_success || cat msg/install_one_drive

qemu: installation
	qemu-system-aarch64 -M raspi3 -kernel install/$(target).img

.PHONY: clean
clean:
	cd c && make clean
	cd asm && make clean
	rm -rf $(obj) *.elf install
