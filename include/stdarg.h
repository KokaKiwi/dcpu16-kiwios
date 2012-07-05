#ifndef STDARG_H_
#define STDARG_H_

#include "types.h"

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
typedef char *va_list;
#endif

#define va_start(ap,offset) (ap = (va_list) (&ap + offset))
#define va_arg(ap, t)   (*(t *)((ap += sizeof(t)) - sizeof(t)))
#define va_end(ap)      (ap = (va_list) 0)

#endif
