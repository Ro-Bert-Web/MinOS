#pragma once

#include "common.h"

#define MAX_PROCS 4
#define STACK_SIZE 0x400000

extern ptr stacks[MAX_PROCS];
extern u32 curr_proc;

void init_procs();
void exec(ptr func);
