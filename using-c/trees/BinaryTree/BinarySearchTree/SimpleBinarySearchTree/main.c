#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct
{
    Node* root;
} Btree;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertLeft(Node* node, int value)
{
    if(node->left == NULL)
    {
        node->left = createNode(value);
    }
    else
    {
        if(value < node->left->value)
        {
            insertLeft(node->left, value);
        }
        if(value > node->left->value)
        {
            insertRight(node->left, value);
        }
    }
}

void insertRight(Node* node, int value)
{
    if(node->right == NULL)
    {
        node->right = createNode(value);
    }
    else
    {
        if(value > node->right->value)
        {
            insertRight(node->right, value);
        }
        if(value < node->right->value)
        {
            insertLeft(node->right, value);
        }

    }
}

void insert(Btree* tree, int value)
{
    if(tree->root == NULL)
    {
        tree->root = createNode(value);
    }
    else
    {
        if(value < tree->root->value)
        {
            insertLeft(tree->root, value);
        }
        if(value > tree->root->value)
        {
            insertRight(tree->root, value);
        }
    }
}

void printBtree(Node* root)
{
    if(root != NULL)
    {
        printBtree(root->left);
        printf("%d ", root->value);
        printBtree(root->right);
    }
}

int main()
{
    int op, valor;
    Btree bt;
    Node* root = NULL;

    bt.root = NULL;

    do
    {
        printf("\n\t 0 - SAIR \t 1 - INSERIR \t 2 - IMPRIMIR \n");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            printf("Finalizado.\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            insert(&bt, valor);
            break;
        case 2:
            printf("\t Arvore binaria:\n");
            printBtree(bt.root);
            break;
        default:
            printf("Invalido\n");

        }
    }
    while(op != 0);

    return 0;
}
