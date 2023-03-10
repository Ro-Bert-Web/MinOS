#include "timer.h"

void init_timer(u32 interval) {
    u32 time = read(TIMER_CLO);
    time += interval;
    write(time, TIMER_C1);
}
