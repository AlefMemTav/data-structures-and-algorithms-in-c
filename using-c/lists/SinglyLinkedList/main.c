#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    LinkedList* list = createList();

    insertNode(list, 10);
    insertNode(list, 20);
    insertNode(list, 30);
    insertNode(list, 40);

    printList(list);
    printf("\n");

    removeNode(list, 20);
    removeNode(list, 30);

    printList(list);
    printf("\n");

    return 0;
}
