ext     := .c
asm     := .s
obj     := .o
cc      := arm-none-eabi-gcc
ccflags := -I ../include
as      := arm-none-eabi-as
asflags :=

sources := $(shell find -type f -name "*$(ext)")
require := $(sources:$(ext)=.d)
assembs := $(sources:$(ext)=$(asm))
objects := $(sources:$(ext)=$(obj))
dirs    := $(shell echo $(sources) | xargs -n1 dirname)

all: $(require) $(objects) ;

%.d: %$(ext)
	@rm -f $@;\
	$(cc) -MM $(ccflags) $< | sed "s:$(shell basename $(@:.d=$(obj))):$@:"                                                          >> $@;\
	$(cc) -MM $(ccflags) $< | sed "s:$(shell basename $(@:.d=$(obj))):$(@:.d=$(obj)):" | sed "s:$(@:.d=$(ext)):$(@:.d=$(asm)):"     >> $@;\
	echo "\t$(as) -o $(@:.d=$(obj)) $(@:.d=$(asm))"                                                                                 >> $@;\
	$(cc) -MM $(ccflags) $< | sed "s:$(shell basename $(@:.d=$(obj))):$(@:.d=$(asm)):"                                              >> $@;\
	echo "\t$(cc) -S -o $(@:.d=$(asm)) $(ccflags) $(@:.d=$(ext))"                                                                   >> $@

include $(require)

.PHONY: clean
clean:
	rm -rf $(assembs) $(objects) $(require)
