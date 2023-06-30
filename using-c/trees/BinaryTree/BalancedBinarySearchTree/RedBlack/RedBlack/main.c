#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node
{
    int key;
    int value;
    Color color;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key, int value, Color color)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->color = color;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* rotateLeft(Node* h)
{
    Node* x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

Node* rotateRight(Node* h)
{
    Node* x = h->left;
    h->left = x->right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    return x;
}

void flipColors(Node* h)
{
    h->color = RED;
    h->left->color = BLACK;
    h->right->color = BLACK;
}

Node* insert(Node* h, int key, int value)
{
    if (h == NULL)
        return createNode(key, value, RED);

    if (key < h->key)
        h->left = insert(h->left, key, value);
    else if (key > h->key)
        h->right = insert(h->right, key, value);
    else
        h->value = value;

    if (h->right != NULL && h->right->color == RED && (h->left == NULL || h->left->color == BLACK))
        h = rotateLeft(h);
    if (h->left != NULL && h->left->color == RED && h->left->left != NULL && h->left->left->color == RED)
        h = rotateRight(h);
    if (h->left != NULL && h->left->color == RED && h->right != NULL && h->right->color == RED)
        flipColors(h);

    return h;
}

int* search(Node* x, int key)
{
    while (x != NULL)
    {
        if (key < x->key)
            x = x->left;
        else if (key > x->key)
            x = x->right;
        else
            return &(x->value);
    }
    return NULL;
}

int main()
{
    Node* root = NULL;

    root = insert(root, 10, 10);
    root = insert(root, 20, 20);
    root = insert(root, 30, 30);
    root = insert(root, 40, 40);
    root = insert(root, 50, 50);

    int* value = search(root, 20);
    if (value != NULL)
        printf("Value: %d\n", *value);
    else
        printf("Key not found\n");

    return 0;
}
