#include "sys.h"
#include "kernel.h"
#include "procs.h"
#include "print.h"
#include "timer.h"
#include "interrupts.h"

u32 handle_sys_call(u32 code) {
    switch (code) {
        case FORK:
            return dup_proc();
        case BLOCK:
            swap(scheduler());
            init_timer(FRAME_LENGTH);
            return 0;
        default:
            //print("Unknown SYS Call\n");
            //halt();
            return -1;
    }
}
