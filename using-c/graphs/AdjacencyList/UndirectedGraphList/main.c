#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node */
typedef struct Node
{
    int item;
    struct Node* next;
} Node;

Node* createNode(int item)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->item = item;
    node->next = NULL;
    return node;
}

/* Linked List */
typedef struct LinkedList
{
    Node* header;
} LinkedList;

/* Undirected Graph using Adjacency List*/
typedef struct Graph
{
    int vertices;
    int edges;
    LinkedList* adjacencyList;
} Graph;

Graph* createGraph(int vertices)
{
    if (vertices <= 0)
    {
        return NULL;
    }
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = 0;
    graph->adjacencyList = (LinkedList*)malloc(vertices * sizeof(LinkedList));
    /*Initializes the graph with NULL*/
    for (int v = 0; v < vertices; v++)
    {
        graph->adjacencyList[v].header = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int v, int w)
{
    if (graph == NULL || v < 0 || w < 0 || v >= graph->vertices || w >= graph->vertices)
    {
        return;
    }
    graph->edges++;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = w;
    newNode->next = graph->adjacencyList[v].header;
    graph->adjacencyList[v].header = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->item = v;
    newNode->next = graph->adjacencyList[w].header;
    graph->adjacencyList[w].header = newNode;
}

void printGraph(Graph* graph)
{
    for (int v = 0; v < graph->vertices; v++)
    {
        printf("%d: ", v);
        Node* current = graph->adjacencyList[v].header;
        while (current != NULL)
        {
            printf("%d ", current->item);
            current = current->next;
        }
        printf("\n");
    }
}

int getDegree(Graph* graph, int v)
{
    if (graph == NULL || v < 0 || v >= graph->vertices)
    {
        return -1;
    }

    int degree = 0;
    Node* current = graph->adjacencyList[v].header;
    while (current != NULL)
    {
        degree++;
        current = current->next;
    }

    return degree;
}

void destroyGraph(Graph* graph)
{
    if (graph == NULL)
    {
        return;
    }
    for (int v = 0; v < graph->vertices; v++)
    {
        Node* current = graph->adjacencyList[v].header;
        while (current != NULL)
        {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjacencyList);
    free(graph);
}

/* Depth-first search */
void dfs(Graph* graph, int vertex, int* visited, int* dfsTree)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* current = graph->adjacencyList[vertex].header;
    while (current != NULL)
    {
        int adjacentVertex = current->item;
        if (!visited[adjacentVertex])
        {
            dfsTree[adjacentVertex] = vertex;
            dfs(graph, adjacentVertex, visited, dfsTree);
        }
        current = current->next;
    }
}

/* Breadth-first search */
void bfs(Graph* graph, int v, int* visited, int* tree)
{
    int vertices = graph->vertices;
    int* queue = (int*)malloc(vertices * sizeof(int));
    int front = 0;
    int rear = 0;

    visited[v] = 1;
    queue[rear++] = v;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* adjacentNode = graph->adjacencyList[currentVertex].header;
        while (adjacentNode != NULL)
        {
            int adjacentVertex = adjacentNode->item;
            if (visited[adjacentVertex] == 0)
            {
                visited[adjacentVertex] = 1;
                tree[adjacentVertex] = currentVertex;
                queue[rear++] = adjacentVertex;
            }
            adjacentNode = adjacentNode->next;
        }
    }

    free(queue);
}

void printTree(Graph* graph, int* tree)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        if (tree[i] != -1)
        {
            printf("%d -> %d\n", tree[i], i);
        }
    }
}

int main()
{
    /* Graph */
    Graph* graph = createGraph(13);

    addEdge(graph, 0, 6);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 5);
    addEdge(graph, 3, 5);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 7, 8);
    addEdge(graph, 9, 11);
    addEdge(graph, 9, 10);
    addEdge(graph, 9, 12);
    addEdge(graph, 11, 12);

    printf("Graph:\n");
    printGraph(graph);

    printf("\n%d vertices, %d edges\n", graph->vertices, graph->edges);

    /* Visited */
    int dfsVisited[13];
    memset(dfsVisited, 0, sizeof(dfsVisited));

    int bfsVisited[13];
    memset(bfsVisited, 0, sizeof(bfsVisited));

    /* Tree */
    int* dfsTree = (int*)malloc(13 * sizeof(int));
    memset(dfsTree, -1, 13 * sizeof(int));

    int* bfsTree = (int*)malloc(13 * sizeof(int));
    memset(bfsTree, -1, 13 * sizeof(int));

    /* Traversal */
    printf("\nDFS Traversal:\n");
    dfs(graph, 1, dfsVisited, dfsTree);

    printf("\n\nBFS Traversal:\n");
    bfs(graph, 1, bfsVisited, bfsTree);

    printf("\n\nDFS Tree:\n");
    printTree(graph, dfsTree);

    printf("\nBFS Tree:\n");
    printTree(graph, bfsTree);

    /* Reverse Graph */
    Graph* reverse = reverseGraph(graph);
    printf("\n");
    printGraph(reverse);

    destroyGraph(graph);
    return 0;
}
