#include "hardware.h"
#include "boot.h"
#include <stdlib.h>
#include <stdio.h>
#include <clock.h>
#include <time.h>

clock_t counter = 0;

clock_t clock()
{
    clock_t ticks;
    unsigned clockAddr = d_clock->address;

    asm("SET A, 1");
    interrupt(clockAddr);
    asm("SET [%ticks], C");

    counter += ticks;

    return counter;
}

time_t time(time_t *timer)
{
    time_t t;

    if (timer)
    {
        t = *timer;
    }
    else
    {
        t = clock() / CLOCKS_PER_SEC;
    }

    return t;
}
