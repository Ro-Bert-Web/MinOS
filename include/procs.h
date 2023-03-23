#pragma once

#include "common.h"

#define MAX_PROCS 4
extern const u32 stack_size;

extern ptr stacks[MAX_PROCS];
extern u32 curr_pid;

void init_procs();
u32 dup_proc();
u32 fork();
void exec(ptr func);
void exit_proc();

u32 scheduler();
void swap(u32 pid);
