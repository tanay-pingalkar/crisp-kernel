#include "sleep.h"
void wait_for_io(uint32_t timer_count)
{
    while (1)
    {
        asm volatile("nop");
        timer_count--;
        if (timer_count <= 0)
            break;
    }
}

void sleep(uint32_t timer_count)
{
    wait_for_io(timer_count);
}
