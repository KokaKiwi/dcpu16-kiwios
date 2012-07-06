#ifndef LIST_H_
#define LIST_H_

#include <types.h>

#define NEW_LIST_ENTRY  (malloc(sizeof(ListEntry)))

typedef struct list_entry ListEntry;
struct list_entry
{
    ListEntry *prev, *next;
    void *value;
};

typedef struct list List;
struct list
{
    ListEntry *root;
    size_t size;
};

extern List *create_list(void);
extern List *create_list_entry(void);
extern ListEntry *get_list_element(List *, unsigned);
extern void append_list_element(List *, ListEntry *);
extern void insert_list_element(List *, ListEntry *, unsigned);
extern void insert_list_list(List *, List *, unsigned);
extern void delete_list_element_at(List *, unsigned);
extern void delete_list_element(List *, ListEntry *);

#endif
