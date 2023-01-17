#pragma once

extern void set_sctlr_el1(u32 val);
extern void set_sctlr_el2(u32 val);
extern void set_sctlr_el3(u32 val);

extern void set_hcr_el2(u32 val);

extern void set_scr_el3(u32 val);

extern void set_spsr_el1(u32 val);
extern void set_spsr_el2(u32 val);
extern void set_spsr_el3(u32 val);

extern void load_elr_el1(u32 val);
extern void load_elr_el2(u32 val);
extern void load_elr_el3(u32 val);
