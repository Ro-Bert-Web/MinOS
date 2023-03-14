#include "procs.h"
#include "sys.h"
#include "utils.h"
#include "mem.h"
#include "print.h"

const u32 stack_size = 0x400000;

ptr stacks[MAX_PROCS];
u32 curr_pid = 0;

void init_procs() {
    for (int i = 0; i < MAX_PROCS; i++) {
        stacks[i] = 0;
    }

    curr_pid = 0;
    stacks[curr_pid] = -1;
}



void exec(ptr func) {
    ((void (*)())func)();
    halt();
}

u32 dup_proc() {
    u32 pid = -1;
    for (int i = 0; i < MAX_PROCS; i++) {
        if (stacks[i] == 0) {
            pid = i;
            break;
        }
    }
    if (pid == -1) {
        return -1;
    }

    ptr src = (curr_pid + 1) * stack_size;
    ptr dest = (pid + 1) * stack_size;

    while (1) {
        u32 val = read(src);
        write(val, dest);

        src -= 4;
        if (src < stacks[curr_pid])
            break;
        dest -= 4;
    }

    stacks[pid] = dest;
    return 0;
}

u32 fork() {
    u32 pid = curr_pid;
    sys_call(FORK);

    if (curr_pid == pid) {
        return 0;
    } else {
        return 1;
    }
}



u32 scheduler() {
    u32 new_pid = curr_pid;
    do {
        new_pid++;
        new_pid %= MAX_PROCS;
    } while (stacks[new_pid] == 0);
    return new_pid;
}

ptr swap(u32 prev_pid, ptr sp) {
    stacks[prev_pid] = sp;
    curr_pid = scheduler();
    return stacks[curr_pid];
}
