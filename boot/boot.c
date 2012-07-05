#include "hardware.h"
#include "stdlib.h"
#include "stdarg.h"
#include "stdio.h"
#include "boot.h"
#include "kernel.h"
#include "color.h"
#include "clock.h"

static unsigned screenId[2] = { 0xf615, 0x7349 };
static unsigned keyboardId[2] = { 0x7406, 0x30cf };
static unsigned clockId[2] = { 0xb402, 0x12d0 };

Device **devices;
unsigned numdevices = 0;

Device *d_screen;
Device *d_keyboard;
Device *d_clock;

void main()
{
    unsigned addr;

    // Initialize hardware
    discover();

    // Initialize screen
    d_screen = getdevice(screenId);
    addr = d_screen->address;

    asm("SET B, [%vram]");
    interrupt(addr);

    // Initialize keyboard
    d_keyboard = getdevice(keyboardId);

    // Initialize clock
    d_clock = getdevice(clockId);
    updateclockfreq();

    print("Booted!\n");

    kernel();
}

void discover()
{
    unsigned i, *j;
    Device *d;

    while (!numdevices)
    {
        connectedhardwaredevices(numdevices);
    }

    devices = (Device **) calloc(numdevices, sizeof(Device *));

    for (i = 0; i < numdevices; i++)
    {
        d = (Device *) malloc(sizeof(Device));

        asm("HWQ [%i]");
#define xx(a,b) j = &(a); asm("SET I, [%j]\nSET [I], " b);

        xx(d->id[0], "A");
        xx(d->id[1], "B");
        xx(d->version, "C");
        xx(d->manufacturer[0], "X");
        xx(d->manufacturer[1], "Y");

#undef xx

        d->address = i;
        devices[i] = d;
    }
}

Device *getdevice(unsigned id[])
{
    Device *d;
    unsigned i;

    d = NULL;

    for (i = 0; i < numdevices; i++)
    {
        if (devices[i]->id[0] == id[0] && devices[i]->id[1] == id[1])
        {
            d = devices[i];

            break;
        }
    }

    return d;
}
