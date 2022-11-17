#include <stdio.h>
#include <stdlib.h>

#include "skiplist.h"


int main(int argc, char const *argv[]) {
    printf("Creating skiplist and populating with 100000 random numbers\n");

    SkipList *my_list;
    my_list = skiplist_create();

    for (int i = 0; i < 100000; i++) {
        skiplist_insert(my_list, rand() % 2000000 - 1000000);
    }

    skiplist_print_pretty(my_list, 0);

    skiplist_free(my_list);
    return 0;
}