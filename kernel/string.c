#include "string.h"

void *memcpy( void *destination, const void *source, size_t num)
{
    size_t i;
    char *d = destination;
    const char *s = source;

    for(i = 0; i < num; i++)
    {
        d[i] = s[i];
    }

    return destination;
}

void *memset(void *ptr, unsigned value, size_t num)
{
    unsigned *p = ptr;

    while(num--)
    {
        *p++ = value;
    }

    return ptr;
}

char *strcpy ( char *destination, const char *source )
{
    while((*destination++ = *source++));

    return destination;
}

char *strncpy ( char *destination, const char *source, size_t num )
{
    while(num--)
    {
        *destination++ = *source++;
    }

    return destination;
}

size_t strlen(const char *str)
{
    size_t i;
    while (*str++)
    {
        i++;
    }

    return i;
}
