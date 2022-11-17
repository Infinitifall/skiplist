#ifndef SKIPLIST
#define SKIPLIST
#endif


/*
The node struct
*/
typedef struct Node {
    int data;
    int height;
    struct Node **succ_array;
    struct Node **pred_array;

} Node;


/*
The skiplist struct
*/
typedef struct SkipList {
    int max_height;
    Node **head_array;

} SkipList;


/*
Description:
    Create a new list and return a pointer to it

Outputs:
    Skiplist *l
*/
SkipList* skiplist_create();


/*
Description:
    Free the list and all associated elements

Inputs:
    SkipList *l
*/
void skiplist_free(SkipList *l);


/*
Description:
    Print all elements of the list in order

    Level 0 has all elements and the higher levels will have
    a successively lower number of elements

Inputs:
    SkipList *l
*/
void skiplist_print(SkipList *l, int level);


/*
Description:
    Pretty print all elements of the list in order

    Level 0 has all elements and the higher levels will have
    a successively lower number of elements

Inputs:
    SkipList *l
*/
void skiplist_print_pretty(SkipList *l, int level);


/*
Description:
    Search for a value in a list and return a pointer to the Node
    If it doesn't exist, return NULL

Inputs:
    SkipList *l
    int data : the value to search for

Outputs:
    Node *n
*/
Node* skiplist_search(SkipList *l, int data);


/*
Description:
    Insert a value in a list
    Duplicates are allowed

Inputs:
    SkipList *l
    int data : the value to be inserted
*/
void skiplist_insert(SkipList *l, int data);


/*
Description:
    Remove a value from a list
    If it doesn't exist, silently fail

Inputs:
    SkipList *l
    int data : the value to be removed
*/
void skiplist_remove(SkipList *l, int data);


/*
Description:
    Get the predecessor of a node

Inputs:
    Node *n

Outputs:
    Node *n_pred : the predecessor
*/
Node* skiplist_nodePred(Node *n, int level);


/*
Description:
    Get the successor of a node

Inputs:
    Node *n

Outputs:
    Node *n_pred : the successor
*/
Node* skiplist_nodeSucc(Node *n, int level);


/*
Description:
    Get the height of a node

Inputs:
    Node *n

Outputs:
    int height
*/
int skiplist_nodeHeight(Node *n);