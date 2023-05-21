#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList* create_list()
{
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    list->header = NULL;
    return list;
}

void insert_node(LinkedList* list, int value)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = list->header;
    list->header = new_node;
}

void remove_node(LinkedList* list, int value)
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

void print_list(LinkedList* list)
{
    Node* current = list->header;

    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
}
