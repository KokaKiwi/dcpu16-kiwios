#ifndef STDLIB_H_
#define STDLIB_H_

#include <types.h>

#define BREAK while(1)

#ifndef SIZE_T_
#define SIZE_T_
typedef unsigned size_t;
#endif

#define NULL ((void *) 0)

#define FLAG_DEFINED    0x01
#define FLAG_FREE       0x02

extern void* malloc(size_t);
extern void* ralloc(size_t);
extern void* calloc(size_t, size_t);

extern void srand(unsigned);
extern int rand(void);

extern int atoi(const char *);
extern int abs(int);

extern void qsort(void *, size_t, size_t, int (*)(const void *, const void *));

#endif
