#pragma once

#include "common.h"

void write(u32 value, ptr addr);
u32 read(ptr addr);
void memcpy(ptr src, ptr dest, u32 n);
