#ifndef STDIO_H_
#define STDIO_H_

#ifndef SIZE_T_
#define SIZE_T_
typedef unsigned size_t;
#endif

extern void putchar(char);
extern void printf(const char *, ...);
extern void print(const char *);
extern void println(const char *);

extern char getchar(void);

extern char *vram;
extern char mask;

extern unsigned screenX;
extern unsigned screenY;

#endif
