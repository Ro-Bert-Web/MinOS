#pragma once

void set_sctlr(u32 el, u32 val);
void set_hcr(u32 el, u32 val);
void set_scr(u32 el, u32 val);
void set_spsr(u32 el, u32 val);
void load_elr(u32 el, ptr val);
