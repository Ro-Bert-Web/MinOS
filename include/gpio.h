#pragma once

#include "common.h"
#include "BCM2837.h"

typedef enum {
    IN = BCM2837_FSEL_INPUT,
    OUT = BCM2837_FSEL_OUTPUT,
    ALT0 = BCM2837_FSEL_ALT0,
    ALT1 = BCM2837_FSEL_ALT1,
    ALT2 = BCM2837_FSEL_ALT2,
    ALT3 = BCM2837_FSEL_ALT3,
    ALT4 = BCM2837_FSEL_ALT4,
    ALT5 = BCM2837_FSEL_ALT5
} FSEL;


void gpio_fsel(u32 port, FSEL mode);

void gpio_set(u32 port);
void gpio_clr(u32 port);
