#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct allocation Allocation;
struct allocation
{
    unsigned flags;
    size_t size;
    void *p;
};

static void *heap_start = (void *) 0x8800;

void* malloc(size_t size)
{
    Allocation *a = (Allocation *) heap_start;
    unsigned defined = a->flags & FLAG_DEFINED;
    unsigned free = a->flags & FLAG_FREE;

    while ((defined && !free) || (defined && a->size < size))
    {
        a += a->size;
        defined = a->flags & FLAG_DEFINED;
        free = a->flags & FLAG_FREE;
    }

    if (!defined)
    {
        a->size = size;
    }

    a->flags = FLAG_DEFINED;

    return &(a->p);
}

void* ralloc(size_t size)
{
    u16 *p;

    p = malloc(size);
    while(size--)
    {
        *p++ = 0;
    }

    return p;
}

void *calloc(size_t num, size_t size)
{
    return malloc(num * size);
}

void free(void *ptr)
{
    Allocation *a = (Allocation *) ((unsigned) (ptr) - 2);
    a->flags = FLAG_DEFINED | FLAG_FREE;
}

static unsigned next = 1;

void srand(unsigned seed)
{
    next = seed;
}

int rand()
{
    next = next * 12432 + 111;

    return (next >> 8);
}

int atoi(const char *s)
{
    int result = 0;
    unsigned neg = 0;
    while (*s)
    {
        if (*s == '-')
        {
            neg++;
        }
        else
        {
            result *= 10;
            result += *s - '0';
        }
        s++;
    }
    if (neg)
    {
        result = -result;
    }
    return result;
}

int abs(int n)
{
    return n < 0 ? -n : n;
}

/*
static void swap(void *x, void *y, size_t l)
{
    char *a = x, *b = y, c;
    while (l--)
    {
        c = *a;
        *a++ = *b;
        *b++ = c;
    }
}

static void sort(char *array, size_t size, int (*cmp)(const void *, const void*), unsigned begin,
        unsigned end)
{
    if (end > begin)
    {
        void *pivot = array + begin;
        unsigned l = begin + size;
        unsigned r = end;
        while (l < r)
        {
            if (cmp(array + l, pivot) <= 0)
            {
                l += size;
            }
            else
            {
                r -= size;
                swap(array + l, array + r, size);
            }
        }
        l -= size;
        swap(array + begin, array + l, size);
        sort(array, size, cmp, begin, l);
        sort(array, size, cmp, r, end);
    }
}
*/

void qsort(void *base, size_t num, size_t size, int (*comp)(const void *, const void *))
{
    //sort(base, size, comp, 0, (num - 1) * size);
}
