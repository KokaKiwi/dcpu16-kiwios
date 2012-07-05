#include "stdlib.h"
#include "hmd.h"

static unsigned hmdId[] = { 0x4cae, 0x74fa };

Device *d_hmd = NULL;

void detect_drive()
{
    if (!d_hmd)
    {
        d_hmd = getdevice(hmdId);
    }
}

unsigned media_present()
{
    unsigned addr, present = 0;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;
        
        asm("SET A, 0");
        interrupt(addr);
        asm("SET [%present], B");
    }
    
    return present;
}

void media_params(Media *media)
{
    unsigned addr, *j;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;
        
        asm("SET A, 1");
        interrupt(addr);
        
#define xx(a,b) j = &(a); asm("SET I, [%j]\nSET [I], " b);
        
        xx(media->words_per_sector, "B");
        xx(media->sectors, "C");
        xx(media->write_locked, "X");
        
#undef xx
    }
}

unsigned hmd_get_flag()
{
    unsigned addr, flag = 0;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;
        
        asm("SET A, 2");
        interrupt(addr);
        
        asm("SET [%flag], B");
    }
    
    return flag;
}

void hmd_set_flag(unsigned flag)
{
    unsigned addr;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;
        
        asm("SET B, A");
        asm("SET A, 3");
        interrupt(addr);
    }
}

void hmd_set_interrupt_message(unsigned msg)
{
    unsigned addr;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;
        
        asm("SET B, A");
        asm("SET A, 5");
        interrupt(addr);
    }
}

void media_read_sector(void *dst, unsigned sector, unsigned size)
{
    unsigned addr;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;

        asm("SET X, A");
        asm("SET A, 0x0010");
        interrupt(addr);
    }
}

void media_write_sector(void *src, unsigned sector, unsigned size)
{
    unsigned addr;
    
    detect_drive();
    
    if (d_hmd)
    {
        addr = d_hmd->address;
        
        asm("SET X, A");
        asm("SET A, 0x0011");
        interrupt(addr);
    }
}
