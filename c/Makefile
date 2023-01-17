gnu     := aarch64-linux-gnu
ext     := .c
asm     := .s
obj     := .o
ccflags := -Wno-builtin-declaration-mismatch -I ../include
asflags :=

sources := $(shell find -type f -name "*$(ext)")
require := $(sources:$(ext)=.d)
assembs := $(sources:$(ext)=$(asm))
objects := $(sources:$(ext)=$(obj))
dirs    := $(shell echo $(sources) | xargs -n1 dirname)

all: $(require) $(objects) ;

%.d: %$(ext)
	@rm -f $@;\
	$(gnu)-gcc -MM $(ccflags) $< | sed "s:$(shell basename $(@:.d=$(obj))):$@:"                                                         >> $@;\
	$(gnu)-gcc -MM $(ccflags) $< | sed "s:$(shell basename $(@:.d=$(obj))):$(@:.d=$(obj)):" | sed "s:$(@:.d=$(ext)):$(@:.d=$(asm)):"    >> $@;\
	echo "\t$(gnu)-as -o $(@:.d=$(obj)) $(asflags) $(@:.d=$(asm))"                                                                      >> $@;\
	$(gnu)-gcc -MM $(ccflags) $< | sed "s:$(shell basename $(@:.d=$(obj))):$(@:.d=$(asm)):"                                             >> $@;\
	echo "\t$(gnu)-gcc -S -o $(@:.d=$(asm)) $(ccflags) $(@:.d=$(ext))"                                                                  >> $@

include $(require)

.PHONY: clean
clean:
	rm -rf $(assembs) $(objects) $(require)
