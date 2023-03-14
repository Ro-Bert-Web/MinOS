#include "sys.h"
#include "kernel.h"
#include "procs.h"
#include "print.h"

u32 handle_sys_call(ptr stack, u32 code) {
    stacks[curr_pid] = stack;

    switch (code) {
        case FORK:
            return dup_proc();
        default:
            //print("Unknown SYS Call\n");
            //halt();
            return -1;
    }
}
