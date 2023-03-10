#pragma once

#include "common.h"
#include "base.h"

#define TIMER_CS    (PBASE + 0x3000)
#define TIMER_CLO   (PBASE + 0x3004)
#define TIMER_CHI   (PBASE + 0x3008)
#define TIMER_C0    (PBASE + 0x300C)
#define TIMER_C1    (PBASE + 0x3010)
#define TIMER_C2    (PBASE + 0x3014)
#define TIMER_C3    (PBASE + 0x3018)

#define TIMER_CS_M0 (1 << 0)
#define TIMER_CS_M1 (1 << 1)
#define TIMER_CS_M2 (1 << 2)
#define TIMER_CS_M3 (1 << 3)


void init_timer(u32 interval);
