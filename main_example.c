#include <stdio.h>
#include <stdlib.h>

#include "src/skiplist.h"


int main(int argc, char const *argv[]) {
    SkipList *my_list = NULL;
    my_list = create_list();
    
    printf("A new skiplist has been created\n\n");
    printf("i <val>         : Insert the element <val> into list\n");
    printf("r <val>         : Remove the element <val> from list\n");
    printf("s <val>         : Search for element <val> in list\n");
    printf("p               : Print list\n");
    printf("P               : Pretty print list\n");
    printf("I <num> <max>   : Insert <num> random numbers from range (-<max>, <max>) to list\n");
    printf("R <num> <max>   : Remove <num> random numbers from range (-<max>, <max>) to list\n");
    printf("\n");

    while(1) {
        printf("> ");
        int val;
        int max;
        char instr;
        scanf(" %c", &instr);

        if (instr == 'i') {
            scanf("%d", &val);
            list_insert(my_list, val);
            printf("Inserted %d\n", val);

        } else if (instr == 'r') {
            scanf("%d", &val);
            list_remove(my_list, val);
            printf("Removed %d\n", val);

        } else if (instr == 's') {
            scanf("%d", &val);
            Node *n = list_search(my_list, val);
            if (n!= NULL) { printf("Found %d, %d\n", val, n->height); }
            else { printf("Not found %d\n", val); }

        } else if (instr == 'p') {
            printf("Printing list\n");
            list_print(my_list);

        } else if (instr == 'P') {
            printf("Pretty printing list\n");
            list_print_pretty(my_list);

        } else if (instr == 'I') {
            scanf("%d %d", &val, &max);
            for (int i = 0; i < val; i++) {
                list_insert(my_list, rand() % (max * 2) - max);
            }
            printf("Inserted %d random numbers from range (-%d, %d)\n", val, max, max);

        } else if (instr == 'R') {
            scanf("%d %d", &val, &max);
            for (int i = 0; i < val; i++) {
                list_remove(my_list, rand() % (max * 2) - max);
            }
            printf("Removed %d random numbers from range (-%d, %d)\n", val, max, max);

        } else if (instr == 'q') {
            break;

        } else {
            printf("Unknown instruction %c!\n", instr);
            
        }
    }

    free_list(my_list);
    return 0;
}