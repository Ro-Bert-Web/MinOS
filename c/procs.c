#include "procs.h"
#include "mem.h"
#include "print.h"

ptr stacks[MAX_PROCS];
u32 curr_proc = 0;

void init_procs() {
    for (int i = 0; i < MAX_PROCS; i++) {
        stacks[i] = 0;
    }

    curr_proc = 0;
    stacks[curr_proc] = 1;
}

void exec(ptr func) {
    ((void (*)())func)();

    u32 pid = -1;
    ptr stack;
    for (int i = 0; i < MAX_PROCS; i++) {
        if (stacks[i] == 0) {
            pid = i;
            break;
        }
    }
    if (pid == -1) {
        print("Could not support anymore processes\n");
        return;
    }

    stack = (pid + 1) * STACK_SIZE;
    stack -= 16 * 17;
    for (int i = 0; i <= 30; i++)
        write(0, stack + i * sizeof(u64));
    write(0, stack + 16 * 16);
    write(0, stack + 16 * 16 + sizeof(u64));
}
