#include "mem.h"

void write(u32 value, ptr addr) {
    *(u32*)addr = value;
}
u32 read(ptr addr) {
    return *(u32*)addr;
}

void memcpy(ptr src, ptr dest, u32 n) {
    u8 *bsrc = (u8*)src;
    u8 *bdest = (u8*)dest;

    for (u32 i = 0; i < n; i++) {
        bdest[i] = bsrc[i];
    }
}
