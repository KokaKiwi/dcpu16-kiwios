#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <hardware.h>
#include "boot.h"
#include <screen.h>
#include <kernel.h>
#include <time.h>
#include <hmd.h>
#include <hat.h>
#include <string.h>
#include <list.h>

void kernel()
{
    List *list = create_list();
    unsigned i;
    
    for(i = 0; i < 10; i++)
    {
        append_list_element(list, NEW_LIST_ENTRY);
    }
    
    insert_list_element(list, NEW_LIST_ENTRY, 5);
    
    delete_list_element_at(list, 3);
    
    printf("Size: %d\n", list->size);
}
