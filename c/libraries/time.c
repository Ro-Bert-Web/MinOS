#include "libraries/time.h"
#include "drivers/mem.h"
#include "libraries/sys.h"
#include "drivers/timer.h"

void sleep(u32 ms) {
    u32 time = read(TIMER_CLO);
    u32 goal = time + ms * 1000;

    do {
        sys_call(BLOCK);
        time = read(TIMER_CLO);
    } while (time < goal);
}
