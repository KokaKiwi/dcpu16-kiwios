#ifndef CLOCK_H_
#define CLOCK_H_

#define CLOCKS_PER_SEC 60

extern void updateclockfreq(void);

extern void enableclockinterrupts();
extern void disableclockinterrupts();

#endif
