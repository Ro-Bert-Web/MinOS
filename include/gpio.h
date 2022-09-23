#pragma once

#include "common.h"

typedef enum {
    IN = 0,
    OUT = 1,
    ALT0 = 4,
    ALT1 = 5,
    ALT2 = 6,
    ALT3 = 7,
    ALT4 = 3,
    ALT5 = 2
} FSEL;


void gpio_fsel(u32 port, FSEL mode);

void gpio_set(u32 port);
void gpio_clr(u32 port);
