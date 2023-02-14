#pragma once

#include "common.h"

void set_sctlr(u32 el, u64 val);
void set_hcr(u32 el, u64 val);
void set_scr(u32 el, u64 val);
void set_spsr(u32 el, u64 val);
void load_elr(u32 el, ptr val);
