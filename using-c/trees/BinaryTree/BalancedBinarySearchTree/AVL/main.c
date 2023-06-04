#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    int height;
    int factor;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    node->factor = 0;
    return node;
}

int maxHeight(int left, int right)
{
    return (left > right) ? left : right;
}

int heightNode(Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    else
    {
        return root->height;
    }
}

int factor(Node* root)
{
    if(root)
    {
        return heightNode(root->left) - heightNode(root->right);
    }
    else
    {
        return 0;
    }
}

Node* leftRotation(Node* root)
{
    Node *child, *b;
    child = root->right;
    b = child->left;

    child->left = root;
    root->right = b;

    root->height = 1 + maxHeight(heightNode(root->left), heightNode(root->right));
    child->height = 1 + maxHeight(heightNode(child->left), heightNode(child->right));

    return child;
}

Node* rightRotation(Node* root)
{
    Node *child, *b;
    child = root->left;
    b = child->right;

    child->right = root;
    root->left = b;

    root->height = 1 + maxHeight(heightNode(root->left), heightNode(root->right));
    child->height = 1 + maxHeight(heightNode(child->left), heightNode(child->right));

    return child;
}

Node* rightLeftRotation(Node* root)
{
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node* leftRightRotation(Node* root)
{
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

Node* balance(Node* root)
{
    int f = factor(root);
    if(f < -1)
    {
        if(factor(root->right) <= 0)
        {
            root = leftRotation(root);
        }
        else
        {
            root = rightLeftRotation(root);
        }
    }
    else if(f > 1)
    {
        if(factor(root->left) >= 0)
        {
            root = rightRotation(root);
        }
        else
        {
            root = leftRightRotation(root);
        }
    }

    return root;
}

Node* insertNode(Node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }
    else
    {
        if(value < root->value)
        {
            root->left = insertNode(root->left, value);
        }
        else if(value > root->value)
        {
            root->right = insertNode(root->right, value);
        }
    }
    root->height = 1 + maxHeight(heightNode(root->left), heightNode(root->right));

    return balance(root);
}

Node* removeNode(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->value == key)
        {
            // remove leaf
            if(root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }
            else
            {
                // remove node that has a child.
                if(root->left == NULL || root->right == NULL)
                {
                    Node* aux;
                    if(root->left != NULL)
                    {
                        aux = root->left;
                    }
                    else
                    {
                        aux = root->right;
                    }
                    free(root);
                    return aux;
                }
                else
                {
                    Node* aux = root->left;
                    while(aux->right != NULL)
                    {
                        aux = aux->right;
                    }
                    root->value = aux->value;
                    aux->value = key;
                    root->left = removeNode(root->left, key);
                    return root;
                }
            }
        }
        else
        {
            if(key < root->value)
            {
                root->left = removeNode(root->left, key);
            }
            if(key > root->value)
            {
                root->right = removeNode(root->right, key);
            }
        }
        root->height = 1 + maxHeight(heightNode(root->left), heightNode(root->right));
        return balance(root);
    }
}

void printTree(Node* root, int level)
{

    if(root != NULL)
    {
        printTree(root->right, level + 1);
        printf("\n\n");
        for(int i = 0; i < level; i++)
        {
            printf("\t");
        }
        printf("%d", root->value);
        printTree(root->left, level + 1);
    }
}

int main()
{
    int op, valor;
    Node* root = NULL;

    do
    {
        printf("\n 0 - EXIT\t 1 - INSERT\t 2 - PRINT\t 3 - REMOVE\n");
        scanf("%d", &op);
        switch(op)
        {
        case 0:
            printf("Finalizado.\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            root = insertNode(root, valor);
            break;
        case 2:
            printTree(root, 1);
            break;
        case 3:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            root = removeNode(root, valor);
            break;
        default:
            printf("Invalido\n");
        }
        fflush(stdin);
        printf("\n");
        getchar();
        system("cls || clear");
    }
    while(op != 0);

    return 0;
}
