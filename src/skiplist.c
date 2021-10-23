#include <stdio.h>
#include <stdlib.h>

#include "skiplist.h"

#define CL_STARTER_HEIGHT 4


int generate_height() {
    int height = 1;
    while (rand() % 2 == 0) {
        height += 1;
    }

    return height;
}


Node* create_node(int data) {
    Node *n = calloc(1, sizeof(Node));
    n->data = data;
    n->height = generate_height();
    n->succ_array = calloc(n->height, sizeof(Node*));
    n->pred_array = calloc(n->height, sizeof(Node*));
    return n;
}


void free_node(Node *n) {
    free(n->succ_array);
    free(n->pred_array);
    free(n);
}


SkipList* create_list() {
    SkipList *l = calloc(1, sizeof(SkipList));
    // create head_array of size CL_STARTER_HEIGHT which we can expand later
    l->head_array = calloc(CL_STARTER_HEIGHT, sizeof(Node*));
    l->max_height = CL_STARTER_HEIGHT;
    return l;
}


void free_list(SkipList *l) {
    Node *curr = l->head_array[0];
    while(curr != NULL) {
        Node *next = curr->succ_array[0];
        free_node(curr);
        curr = next;
    }

    free(l->head_array);
    free(l);
}


void list_print(SkipList *l) {
    Node *curr = l->head_array[0];
    while(curr != NULL) {
        printf("%20d, %2d\n", curr->data, curr->height);
        curr = curr->succ_array[0];
    }
}


void list_print_pretty(SkipList *l) {
    Node *curr = l->head_array[0];
    while(curr != NULL) {
        printf("%20d, ", curr->data);
        for (int i = 0; i < curr->height; i++) {
            printf("_");
        }

        printf("\n");
        curr = curr->succ_array[0];
    }
}


Node* list_search(SkipList *l, int data) {
    // check levels in head_array from top to bottom
    int curr_height = l->max_height;
    while(curr_height >= 0) {
        Node *next = l->head_array[curr_height];
        if (next == NULL) {
            curr_height -=1;

        } else if (next->data > data) {
            curr_height -=1;

        } else if (next->data == data) {
            return next;

        } else {
            break;
        }
    }
    
    // traverse the skip list going down or forward
    Node *curr = l->head_array[curr_height];
    while(curr_height >= 0) {
        Node *next = curr->succ_array[curr_height];
        if (next == NULL) {
            curr_height -= 1;

        } else if (next->data > data) {
            curr_height -= 1;

        } else if (next->data == data) {
            return next;

        } else {
            curr = next;
        }
    }

    return NULL;
}


void list_insert(SkipList *l, int data) {
    Node *n = create_node(data);
    
    // increase size of head_array by a set amount if necessary (doubling size is unnecessary
    // because height is not expected to exceed log(n))
    while (l->max_height < n->height) {
        l->head_array = realloc(l->head_array, CL_STARTER_HEIGHT * sizeof(Node*) +  sizeof(*l->head_array));
        l->max_height += CL_STARTER_HEIGHT;
    }

    // check levels in head_array from top to bottom
    int curr_height = l->max_height;
    while(curr_height >= 0) {
        Node *next = l->head_array[curr_height];
        if (next == NULL) {
            if (n->height - 1 >= curr_height) {
                l->head_array[curr_height] = n;
                printf("%p\n", l->head_array[curr_height]);
            }

            curr_height -=1;

        } else if (next->data > data) {
            if (n->height - 1 >= curr_height) {
                n->succ_array[curr_height] = next;
                next->pred_array[curr_height] = n;
                l->head_array[curr_height] = n;
            }

            curr_height -=1;

        } else {
            break;
        }
    }

    // traverse the skip list going down or forward
    Node *curr = l->head_array[curr_height];
    while(curr_height >= 0) {
        Node *next = curr->succ_array[curr_height];
        if (next == NULL) {
            if (n->height - 1 >= curr_height) {
                curr->succ_array[curr_height] = n;
                n->pred_array[curr_height] = curr;
            }

            curr_height -= 1;

        } else if (next->data > data) {
            if (n->height - 1 >= curr_height) {
                n->succ_array[curr_height] = next;
                next->pred_array[curr_height] = n;
                n->pred_array[curr_height] = curr;
                curr->succ_array[curr_height] = n;
            }
            
            curr_height -= 1;
        } else {
            curr = next;
        }
    }
}


void list_remove(SkipList *l, int data) {
    // get pointer to the element using list_search
    Node *curr = list_search(l, data);

    if(curr == NULL) {
        return;
    }

    // set pointers of succ and pred on each level
    for (int i = 0; i <curr->height; i++) {
        Node *succ = curr->succ_array[i];
        Node *pred = curr->pred_array[i];

        if (succ != NULL) {
            if (pred != NULL) {
                succ->pred_array[i] = pred;
                pred->succ_array[i] = succ;

            } else {
                succ->pred_array[i] = NULL;
                l->head_array[i] = succ;
            }

        } else {
            if (pred != NULL) {
                pred->succ_array[i] = NULL;

            } else {
                l->head_array[i] = NULL;
            }
        }
    }

    free_node(curr);
}

