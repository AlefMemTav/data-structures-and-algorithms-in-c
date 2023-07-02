#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

typedef struct node
{
    int value;
    struct node* next;
} Node;

typedef struct LinkedList
{
    Node* header;
} LinkedList;

LinkedList* createList();

void insertNode(LinkedList* linkedList, int value);

void removeNode(LinkedList* linkedList, int value);

void printList(LinkedList* linkedList);

#endif // LINKEDLIST_H_INCLUDED
