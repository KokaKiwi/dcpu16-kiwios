#ifndef BOOT_H_
#define BOOT_H_

#include "hardware.h"

extern void discover();
extern Device *getdevice(unsigned []);

extern Device **devices;
extern unsigned numdevices;

extern Device *d_screen;
extern Device *d_keyboard;
extern Device *d_clock;

#endif
