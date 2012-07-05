#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <hardware.h>
#include "boot.h"
#include <screen.h>
#include <kernel.h>
#include <time.h>
#include <hmd.h>

void kernel()
{
    Media media;
    char *data;
    unsigned sector, size;
    
    media_params(&media);
    
    sector = 10;
    size = 2;
    
    data = malloc(media.words_per_sector * size);
    
    media_read_sector(data, sector, size);
}
