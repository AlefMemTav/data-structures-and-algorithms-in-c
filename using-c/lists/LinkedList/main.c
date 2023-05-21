#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    LinkedList* list = create_list();

    insert_node(list, 10);
    insert_node(list, 20);
    insert_node(list, 30);
    insert_node(list, 40);

    print_list(list);
    printf("\n");

    remove_node(list, 20);
    remove_node(list, 30);

    print_list(list);
    printf("\n");

    return 0;
}
