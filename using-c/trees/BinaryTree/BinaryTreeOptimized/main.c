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

Node* searchNode(Node* root, int key)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        if(root->value == key)
        {
            return root;
        }
        if(key < root->value)
        {
            return searchNode(root->left, key);
        }
        if(key > root->value)
        {
            return searchNode(root->right, key);
        }
    }
    return NULL;
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
            return root;
        }
    }
    return NULL;
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

int heightTree(Node* root)
{
    if(root == NULL || (root->right == NULL && root->left == NULL))
    {
        return 0;
    }
    else
    {
        int left = 1 + heightTree(root->left);
        int right = 1 + heightTree(root->right);
        if(left > right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
}

int heightNode(Node* root, int key)
{
    Node* node = searchNode(root, key);
    if(node != NULL)
    {
        return heightTree(node);
    }
    else
    {
        return -1;
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



int main()
{
    int op, valor;
    Node* root = NULL;

    do
    {
        printf("\n\t 0 - SAIR \t 1 - INSERIR \t 2 - IMPRIMIR \t 3 - PESQUISAR \t 4 - REMOVER \t 5 - ALTURA DA ARVORE \t 6 - ALTURA DO NO\n");
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
            printf("Resultado: %d\n", searchNode(root, valor));
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            root = removeNode(root, valor);
            break;
        case 5:
            printf("Altura da arvore: %d\n", heightTree(root));
            break;
        case 6:
            printf("\t Digite o valor a ser buscado:\n");
            scanf("%d", &valor);
            printf("Altura do no: %d\n", heightNode(root, valor));
            break;
        default:
            printf("Invalido\n");
        }
    }
    while(op != 0);

    return 0;
}
