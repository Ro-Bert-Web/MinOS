#include "drivers/timer.h"
#include "drivers/mem.h"

void init_timer(u32 interval) {
    u32 time = read(TIMER_CLO);
    time += interval;
    write(time, TIMER_C1);
}
