#include <stdlib.h>
#include <list.h>

List *create_list()
{
    List *list = malloc(sizeof(List));
    ListEntry *root = malloc(sizeof(ListEntry));
    
    root->prev = root;
    root->next = root;
    
    return list;
}

ListEntry *get_list_element(List *list, unsigned index)
{
    ListEntry *cur = list->root;
    
    while (index--)
    {
        cur = cur->next;
    }
    
    return cur;
}

void append_list_element(List *list, ListEntry *elt)
{
    ListEntry *last = list->root->prev;
    last->next = elt;
    list->root->prev = elt;
    
    elt->next = list->root;
    elt->prev = last;
    
    list->size++;
}

void insert_list_element(List *list, ListEntry *elt, unsigned index)
{
    ListEntry *entry = get_list_element(list, index);
    ListEntry *prev = entry->prev;
    
    prev->next = elt;
    entry->prev = elt;
    
    list->size++;
}

void insert_list_list(List *dst, List *src, unsigned index)
{
    ListEntry *entry = get_list_element(dst, index);
    ListEntry *prev = entry->prev;
    ListEntry *first = src->root->next;
    ListEntry *last = src->root->prev;
    
    prev->next = first;
    first->prev = prev;
    
    entry->prev = last;
    last->next = entry;
    
    dst->size += src->size;
}

void delete_list_element_at(List *list, unsigned index)
{
    delete_list_element(list, get_list_element(list, index));
}

void delete_list_element(List *list, ListEntry *elt)
{
    elt->prev->next = elt->next;
    elt->next->prev = elt->prev;
    
    list->size--;
}

