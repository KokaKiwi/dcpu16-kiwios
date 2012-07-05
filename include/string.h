#ifndef STRING_H_
#define STRING_H_

#ifndef SIZE_T_
#define SIZE_T_
typedef unsigned size_t;
#endif

extern void *memcpy(void *, const void *, size_t);
extern void *memset(void *, unsigned, size_t);
extern char *strcpy (char *, const char *);
extern char *strncpy (char *, const char *, size_t);
extern size_t strlen(const char *);

#endif
