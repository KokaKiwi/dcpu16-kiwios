#include "hardware.h"
#include "boot.h"
#include "clock.h"

void updateclockfreq()
{
    unsigned clock_value = 60 / CLOCKS_PER_SEC;
    unsigned clockAddr = d_clock->address;

    asm("SET A, 0");
    asm("SET B, [%clock_value]");
    interrupt(clockAddr);
}

void enableclockinterrupts()
{

}
