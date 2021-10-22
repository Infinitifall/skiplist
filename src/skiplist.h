#ifndef SKIPLIST_592826347051084432638762231
#define SKIPLIST_592826347051084432638762231
#endif


typedef struct Node {
    int data;
    int height;
    struct Node **succ_array;  // succ for each level from 0 to height - 1
    struct Node **pred_array;  // pred for each level from 0 to height - 1

} Node;


typedef struct SkipList {
    int max_height;     // max height we can store without needing to realloc head_array
    Node **head_array;  // succ for each level from 0 to height - 1

} SkipList;


/*
Description:
    Create a new list and return a pointer to it

Outputs:
    Skiplist *l : the list
*/
SkipList* create_list();


/*
Description:
    Free the list and all associated elements

Inputs:
    SkipList *l : the list
*/
void free_list(SkipList *l);


/*
Description:
    Print all elements of the list in order

Inputs:
    SkipList *l : the list
*/
void list_print(SkipList *l);


/*
Description:
    Pretty print all elements of the list in order

Inputs:
    SkipList *l : the list
*/
void list_print_pretty(SkipList *l);


/*
Description:
    Search for a value in a list and return a pointer to the Node
    If it doesn't exist, return NULL

Inputs:
    SkipList *l : the list
    int data : the value

Outputs:
    Node *n : the Node*
*/
Node* list_search(SkipList *l, int data);


/*
Description:
    Insert a value in a list
    Duplicates are allowed

Inputs:
    SkipList *l : the list
    int data : the value
*/
void list_insert(SkipList *l, int data);


/*
Description:
    Remove a value from a list
    If it doesn't exist, silently fail

Inputs:
    SkipList *l : the list
    int data : the value
*/
void list_remove(SkipList *l, int data);

