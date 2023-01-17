gnu     := aarch64-linux-gnu
flags   := -I ../include

src     := $(shell find -type f -name "*.s")
obj     := $(src:.s=.o)

all: $(obj)

%.o: %.s
	$(gnu)-as -o $@ $(flags) $(@:.o=.s)

.PHONY: clean
clean:
	rm -rf $(obj)
