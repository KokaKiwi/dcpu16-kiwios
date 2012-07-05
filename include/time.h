#ifndef TIME_H_
#define TIME_H_

#ifndef CLOCK_T_
#define CLOCK_T_
typedef unsigned clock_t;
#endif

#ifndef TIME_T_
#define TIME_T_
typedef unsigned time_t;
#endif

extern clock_t clock(void);
extern time_t time(time_t *);

#endif
