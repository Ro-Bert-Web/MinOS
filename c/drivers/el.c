#include "common.h"
#include "el.h"
#include "el_priv.h"

void set_sctlr(u32 el, u64 val) {
    switch (el) {
        case 1:
            set_sctlr_el1(val);
            break;
        case 2:
            set_sctlr_el2(val);
            break;
        case 3:
            set_sctlr_el3(val);
            break;
    }
}


void set_hcr(u32 el, u64 val) {
    switch (el) {
        case 2:
            set_hcr_el2(val);
            break;
    }
}


void set_scr(u32 el, u64 val) {
    switch (el) {
        case 3:
            set_scr_el3(val);
            break;
    }
}


void set_spsr(u32 el, u64 val) {
    switch (el) {
        case 1:
            set_spsr_el1(val);
            break;
        case 2:
            set_spsr_el2(val);
            break;
        case 3:
            set_spsr_el3(val);
            break;
    }
}


void load_elr(u32 el, ptr val) {
    switch (el) {
        case 1:
            load_elr_el1(val);
            break;
        case 2:
            load_elr_el2(val);
            break;
        case 3:
            load_elr_el3(val);
            break;
    }
}
