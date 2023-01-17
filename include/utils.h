#pragma once

#include "common.h"

extern void set_sctlr_el1(u32);
extern void set_hcr_el2(u32);
extern void set_scr_el3(u32);
extern void set_spsr_el3(u32);
extern void set_elr_el3(u32);
extern u32 get_el();

extern void delay(u32);
