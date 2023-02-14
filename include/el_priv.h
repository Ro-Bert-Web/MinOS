#pragma once

#include "common.h"

extern void set_sctlr_el1(u64 val);
extern void set_sctlr_el2(u64 val);
extern void set_sctlr_el3(u64 val);

extern void set_hcr_el2(u64 val);

extern void set_scr_el3(u64 val);

extern void set_spsr_el1(u64 val);
extern void set_spsr_el2(u64 val);
extern void set_spsr_el3(u64 val);

extern void load_elr_el1(ptr val);
extern void load_elr_el2(ptr val);
extern void load_elr_el3(ptr val);
