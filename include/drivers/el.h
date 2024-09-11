#pragma once

#include "common.h"

#define SCTLR_RESERVED      (3 << 28) | (3 << 22) | (1 << 20) | (1 << 11)
#define SCTLR_EE_ENDIAN     (1 << 25)
#define SCTLR_EOE_ENDIAN    (1 << 24)
#define SCTLR_I_CACHE       (1 << 12)
#define SCTLR_D_CACHE       (1 << 2)
#define SCTLR_MMU           (1 << 0)

#define HCR_RW          (1 << 31)

#define SCR_RESERVED    (3 << 4)
#define SCR_RW          (1 << 10)
#define SCR_NS          (1 << 0)

#define SPSR_MASK_ALL   (7 << 6)
#define SPSR_EL1h       (5 << 0)

void set_sctlr(u32 el, u64 val);
void set_hcr(u32 el, u64 val);
void set_scr(u32 el, u64 val);
void set_spsr(u32 el, u64 val);
void load_elr(u32 el, ptr val);
