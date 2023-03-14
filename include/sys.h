#pragma once

#include "common.h"

typedef enum {
    FORK
} SYS_Calls;

u32 sys_call();
u32 handle_sys_call(ptr stack, u32 code);
