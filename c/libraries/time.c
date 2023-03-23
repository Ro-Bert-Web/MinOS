#include "time.h"
#include "sys.h"
#include "timer.h"
#include "mem.h"

void sleep(u32 ms) {
    u32 time = read(TIMER_CLO);
    u32 goal = time + ms * 1000;

    do {
        sys_call(BLOCK);
        time = read(TIMER_CLO);
    } while (time < goal);
}
