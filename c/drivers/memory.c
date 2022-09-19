#include "memory.h"

void write(u32 value, void *addr) {
    *(u32*)addr = value;
}
u32 read(void *addr) {
    return *(u32*)addr;
}
