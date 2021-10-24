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


Node* skiplist_create_node(int data) {
    Node *n = calloc(1, sizeof(Node));
    n->data = data;
    n->height = generate_height();
    n->succ_array = calloc(n->height, sizeof(Node*));
    n->pred_array = calloc(n->height, sizeof(Node*));
    return n;
}


void skiplist_free_node(Node *n) {
    free(n->succ_array);
    free(n->pred_array);
    free(n);
}


SkipList* skiplist_create() {
    SkipList *l = calloc(1, sizeof(SkipList));
    // create head_array of size CL_STARTER_HEIGHT which we can expand later
    l->head_array = calloc(CL_STARTER_HEIGHT, sizeof(Node*));
    l->max_height = CL_STARTER_HEIGHT;
    return l;
}


void skiplist_free(SkipList *l) {
    Node *curr = l->head_array[0];
    while(curr != NULL) {
        Node *next = curr->succ_array[0];
        skiplist_free_node(curr);
        curr = next;
    }

    free(l->head_array);
    free(l);
}


void skiplist_print(SkipList *l, int level) {
    if ((level >= l->max_height) || (level < 0)) {
        printf("No elements!\n");
        return;
    }

    Node *curr = l->head_array[level];
    while(curr != NULL) {
        printf("%20d, %2d\n", curr->data, curr->height);
        curr = skiplist_nodeSucc(curr, level);
    }
}


void skiplist_print_pretty(SkipList *l, int level) {
    if ((level >= l->max_height) || (level < 0)) {
        printf("No elements!\n");
        return;
    }
    
    Node *curr = l->head_array[level];
    while(curr != NULL) {
        printf("%20d, ", curr->data);
        for (int i = 0; i < curr->height; i++) {
            printf("_");
        }

        printf("\n");
        curr = curr->succ_array[level];
    }
}


Node* skiplist_search(SkipList *l, int data) {
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


void skiplist_insert(SkipList *l, int data) {
    Node *n = skiplist_create_node(data);
    
    // increase size of head_array by a set amount if necessary (doubling size is unnecessary
    // because height is not expected to exceed log(n))
    while (l->max_height < n->height) {
        Node **temp = calloc(l->max_height + CL_STARTER_HEIGHT, sizeof(Node*));
        for (int i = 0; i < l->max_height; i++) {
            if (l->head_array[i] != NULL) {
                temp[i] = l->head_array[i];
            }
        }
        
        l->head_array = temp;
        l->max_height += CL_STARTER_HEIGHT;
    }

    // check levels in head_array from top to bottom
    int curr_height = l->max_height;
    while(curr_height >= 0) {
        Node *next = l->head_array[curr_height];
        if (next == NULL) {
            if (n->height - 1 >= curr_height) {
                l->head_array[curr_height] = n;
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


void skiplist_remove(SkipList *l, int data) {
    // get pointer to the element using list_search
    Node *curr = skiplist_search(l, data);

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

    skiplist_free_node(curr);
}


Node* skiplist_nodePred(Node *n, int level) {
    return n->pred_array[level];
}


Node* skiplist_nodeSucc(Node *n, int level) {
    return n->succ_array[level];
}


int skiplist_nodeHeight(Node *n) {
    return n->height;
}

