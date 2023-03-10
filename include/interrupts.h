#pragma once

#include "common.h"
#include "base.h"

extern void vtable_init();
extern void enable_irq();
extern void disable_irq();


void enable_timer_interrupt();

void invalid_interrupt(u64 type, u64 esr, u64 elr);
void handle_irq();


#define IRQ_BASIC_PENDING   (PBASE + 0xB200)
#define IRQ_PENDING_1       (PBASE + 0xB204)
#define IRQ_PENDING_2       (PBASE + 0xB208)
#define FIQ_CONTROL         (PBASE + 0xB20C)
#define ENABLE_IRQS_1       (PBASE + 0xB210)
#define ENABLE_IRQS_2       (PBASE + 0xB214)
#define ENABLE_BASIC_IRQS   (PBASE + 0xB218)
#define DISABLE_IRQS_1      (PBASE + 0xB21C)
#define DISABLE_IRQS_2      (PBASE + 0xB220)
#define DISABLE_BASIC_IRQS  (PBASE + 0xB224)

#define SYSTEM_TIMER_IRQ_0  (1 << 0)
#define SYSTEM_TIMER_IRQ_1  (1 << 1)
#define SYSTEM_TIMER_IRQ_2  (1 << 2)
#define SYSTEM_TIMER_IRQ_3  (1 << 3)
