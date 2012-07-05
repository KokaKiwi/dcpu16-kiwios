#include "types.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"
#include "hardware.h"
#include "boot.h"

char *vram = (char *) 0x8000;
char mask = 0xf000;

unsigned screenX = 0;
unsigned screenY = 0;

void putchar(char character)
{
    uchar *vpointer = (uchar *) (vram + 32 * screenY + screenX);
    uchar c = (uchar) character;
    
    switch (c)
    {
        case '\n':
            screenX = 0;
            screenY++;
            break;
        default:
            *vpointer = (c & 0xff) | mask;
            screenX++;
            break;
    }
    
    if (screenY > 11)
    {
        screenY = 11;
    }
    if (screenX > 31)
    {
        screenX = 0;
        screenY++;
    }
}

void printf_putu(unsigned d, unsigned base)
{
    static uchar buf[16];
    unsigned i = 0;
    
    if (d)
    {
        while (d)
        {
            buf[i++] = "0123456789abcdef"[d % base];
            
            d /= base;
        }
        
        while (i--)
        {
            putchar(buf[i]);
        }
    }
    else
    {
        putchar('0');
    }
}

void printf_putd(int d, unsigned base)
{
    if (d < 0)
    {
        putchar('-');
        d = -d;
    }
    
    printf_putu(d, base);
}

void printf(const char *format, ...)
{
    va_list args;
    char c;
    unsigned i = 0;
    
    va_start(args, 3);
    
    while ((c = *format++))
    {
        switch (c)
        {
            case '%':
                switch (*format++)
                {
                    case 'd':
                        printf_putd(va_arg(args, int), 10);
                        break;
                    case 'u':
                        printf_putu(va_arg(args, unsigned), 10);
                        break;
                    case 'x':
                        printf_putu(va_arg(args, unsigned), 16);
                        break;
                    case 'o':
                        printf_putu(va_arg(args, unsigned), 8);
                        break;
                    case 'b':
                        printf_putu(va_arg(args, unsigned), 2);
                        break;
                    case 's':
                        print(va_arg(args, char *) );
                        break;
                }
                if (++i == 2)
                {
                    args++;
                }
                break;
            default:
                putchar(c);
                break;
        }
    }
}

void print(const char *str)
{
    while (*str)
    {
        putchar(*str);
        str++;
    }
}

void println(const char *str)
{
    print(str);
    putchar('\n');
}

char getchar()
{
    char c = 0;
    unsigned keyboardAddr = d_keyboard->address;
    
    asm("SET A, 1");
    interrupt(keyboardAddr);
    asm("SET [%c], C");
    
    if(c == 0x11)
    {
        c = '\n';
    }
    
    return c;
}
