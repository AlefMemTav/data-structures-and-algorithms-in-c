#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct node
{
    int value;
    struct node* next;
} Node;

typedef struct list
{
    Node* header;
} LinkedList;

LinkedList* create_list();

void insert_node(LinkedList* list, int value);

void remove_node(LinkedList* list, int value);

void print_list(LinkedList* list);

#endif // LINKEDLIST_H_INCLUDED
