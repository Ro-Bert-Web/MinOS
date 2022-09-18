#include "BCM2837.h"

typedef unsigned int uint;

void main() {
    void *addr = (void*)(0x3f200000 + 0x28);
    *(uint*)addr = 0x200000;
}
