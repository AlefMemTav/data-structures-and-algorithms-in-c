#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct node
{
    char* key;
    int value;
    struct node* next;
} Node;

Node* table[TABLE_SIZE];

int hash(char* key)
{
    int hashval = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        hashval += key[i];
    }
    return hashval % TABLE_SIZE;
}

void insert(char* key, int value)
{
    int index = hash(key);
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table[index];
    table[index] = new_node;
}

int search(char* key)
{
    int index = hash(key);
    Node* current = table[index];
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

void remove_node(char* key)
{
    int index = hash(key);
    Node* current = table[index];
    Node* prev = NULL;
    while (current != NULL)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev == NULL)
            {
                table[index] = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main()
{
    insert("one", 1);
    insert("two", 2);
    insert("three", 3);
    insert("four", 4);
    insert("five", 5);

    printf("%d\n", search("three")); // output: 3
    printf("%d\n", search("six")); // output: -1

    remove_node("four");
    printf("%d\n", search("four")); // output: -1

    return 0;
}
