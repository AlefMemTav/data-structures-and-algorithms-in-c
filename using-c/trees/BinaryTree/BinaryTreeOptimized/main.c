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
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* root, int value)
{
    if(root == NULL)
    {
        return root = createNode(value);
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
        return root;
    }
}

Node* searchNode(Node* root, int key)
{
    if(root == NULL)
    {
        return 0;
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

void inOrder(Node* root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->value);
        inOrder(root->right);
    }
}

void preOrder(Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->value);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->value);
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

int numberLeaves(Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return numberLeaves(root->left) + numberLeaves(root->right);
    }
}

int numberNodes(Node* root)
{
    return (root == NULL) ? 0 : 1 + numberNodes(root->left) + numberNodes(root->right);
}

void levelNode(Node* root, int level)
{
    if(root != NULL)
    {
        levelNode(root->left, level+1);
        printf("%d(l. %d) ", root->value, level);
        levelNode(root->right, level+1);
    }
}

int main()
{
    int op, valor;
    Node* root = NULL;

    do
    {
        printf("\n 0 - EXIT\t 1 - INSERT\t 2 - IN-ORDER\t 3 - PRE-ORDER\t 4 - POST-ORDER\t 5 - SEARCH");
        printf("\n 6 - REMOVE\t 7 - H.TREE\t 8 - H.NODE\t 9 - SIZE\t 10 - N.NODE\t 11 - N.LEAVES");
        printf("\n 12 - LEVEL\n");
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
            printf("\t Arvore binaria em ordem:\n");
            inOrder(root);
            break;
        case 3:
            printf("\t Arvore binaria pre ordem:\n");
            preOrder(root);
            break;
        case 4:
            printf("\t Arvore binaria pos ordem:\n");
            postOrder(root);
            break;
        case 5:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            if(searchNode(root,valor) != NULL)
            {
                printf("Resultado: %d\n", searchNode(root, valor)->value);
            }
            else
            {
                printf("Resultado: 0\n");
            }
            break;
        case 6:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            root = removeNode(root, valor);
            break;
        case 7:
            printf("Altura da arvore: %d\n", heightTree(root));
            break;
        case 8:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            printf("Altura do no: %d\n", heightNode(root, valor));
            break;
        case 9:
            printf("Tamanho da arvore: %d\n", treeSize(root));
            break;
        case 10:
            printf("Numero de nos: %d\n", numberNodes(root));
            break;
        case 11:
            printf("Numero de folhas: %d\n", numberLeaves(root));
            break;
        case 12:
            printf("Nivel do no: \n");
            levelNode(root, 0);
            break;
        default:
            printf("Invalido\n");
        }
        fflush(stdin);
        printf("\n\t press");
        getchar();
        system("cls || clear");
    }
    while(op != 0);

    return 0;
}
