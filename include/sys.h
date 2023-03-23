#pragma once

#include "common.h"

typedef enum {
    FORK,
    BLOCK
} SYS_Calls;

u32 sys_call(u32 code);
u32 handle_sys_call(u32 code);
