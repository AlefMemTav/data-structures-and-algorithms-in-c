#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value)
{
    if(root == NULL)
    {
        return root = createNode(value);
    }
    else
    {
        if(value < root->value)
        {
            root->left = insert(root->left, value);
        }
        if(value > root->value)
        {
            root->right = insert(root->right, value);
        }
        return root;
    }
    return NULL;
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

int treeSize(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {

        return 1 + treeSize(root->left) + treeSize(root->right);
    }
}

int search(Node* root, int key)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        if(root->value == key)
        {
            return root->value;
        }
        if(key < root->value)
        {
            return search(root->left, key);
        }
        if(key > root->value)
        {
            return search(root->right, key);
        }
    }
}

int main()
{
    int op, valor;
    Node* root = NULL;

    do
    {
        printf("\n\t 0 - SAIR \t 1 - INSERIR \t 2 - IMPRIMIR \t 3 - PESQUISAR \n");
        scanf("%d", &op);

        switch(op)
        {
        case 0:
            printf("Finalizado.\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            root = insert(root, valor);
            break;
        case 2:
            printf("\t Arvore binaria:\n");
            printBtree(root);
            printf("\n\t Tamanho da arvore: %d\n", treeSize(root));
            break;
        case 3:
            printf("\t Digite o valor a ser buscado:\n");
            scanf("%d", &valor);
            printf("Resultado: %d\n", search(root, valor));
            break;
        default:
            printf("Invalido\n");
        }
    }
    while(op != 0);

    return 0;
}
