#ifndef HARDWARE_H_
#define HARDWARE_H_

typedef unsigned int_t;

typedef struct device Device;
struct device
{
    unsigned id[2];
    unsigned version;
    unsigned manufacturer[2];
    unsigned address;
};

#define connectedhardwaredevices(ret) asm("HWN [%" #ret "]")
#define interrupt(addr) asm("HWI [%" #addr "]")
#define setinterrupthandler(handler) asm("IAS %" #handler);

#endif
