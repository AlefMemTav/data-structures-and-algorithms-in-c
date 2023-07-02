#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* createList()
{
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->header = NULL;
    return list;
}

void insertNode(LinkedList* list, int value)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->header;
    list->header = new_node;
}

void removeNode(LinkedList* list, int value)
{
    Node* current = list->header;
    Node* previous = NULL;

    while (current != NULL)
    {
        if (current->value == value)
        {
            if (previous == NULL)
            {
                list->header = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void printList(LinkedList* list)
{
    Node* current = list->header;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}
