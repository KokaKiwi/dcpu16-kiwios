#include "stdio.h"
#include "stdlib.h"
#include "hardware.h"
#include "boot.h"
#include "screen.h"

void scroll(unsigned length)
{
    unsigned i;
    char *src, *dst;
    if (length < SCREEN_HEIGHT)
    {
        for(i = length; i < SCREEN_HEIGHT; i++)
        {
            src = (char *)(vram + (i * SCREEN_WIDTH));
            dst = (char *)(vram + ((i - length) * SCREEN_WIDTH));

            memcpy(dst, src, SCREEN_WIDTH);
        }
    }
}

void clearScreen()
{
    unsigned i;
    for (i = 0; i < (SCREEN_WIDTH * SCREEN_HEIGHT); i++)
    {
        vram[i] = 0;
    }
}
