#include "memory.h"

void write(u32 value, void *addr) {
    *(u32*)addr = value;
}
u32 read(void *addr) {
    return *(u32*)addr;
}

void memcpy(void *src, void *dest, u32 n) {
    char *bsrc = (char*)src;
    char *bdest = (char*)dest;

    for (int i = 0; i < n; i++) {
        bdest[i] = bsrc[i];
    }
}
