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

/* Directed Graph using Adjacency List*/
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

Graph* reverseGraph(Graph* graph)
{
    if (graph == NULL)
    {
        return NULL;
    }

    int vertices = graph->vertices;
    Graph* reversedGraph = createGraph(vertices);

    for (int v = 0; v < vertices; v++)
    {
        Node* current = graph->adjacencyList[v].header;
        while (current != NULL)
        {
            int adjacentVertex = current->item;
            addEdge(reversedGraph, adjacentVertex, v);
            current = current->next;
        }
    }

    return reversedGraph;
}

int getDegree(Graph* graph, int v)
{
    if (graph == NULL || v < 0 || v >= graph->vertices)
    {
        return -1;
    }

    int inDegree = 0;
    int outDegree = 0;

    // Calcula in-degree contando as arestas que apontam para o vértice v
    for (int i = 0; i < graph->vertices; i++)
    {
        Node* current = graph->adjacencyList[i].header;
        while (current != NULL)
        {
            if (current->item == v)
            {
                inDegree++;
                break;
            }
            current = current->next;
        }
    }

    // Calcula out-degree contando as arestas que partem do vértice v
    Node* current = graph->adjacencyList[v].header;
    while (current != NULL)
    {
        outDegree++;
        current = current->next;
    }

    return inDegree + outDegree;
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
void dfs(Graph* graph, int vertex, int* visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    Node* current = graph->adjacencyList[vertex].header;
    while (current != NULL)
    {
        int adjacentVertex = current->item;
        if (!visited[adjacentVertex])
        {
            dfs(graph, adjacentVertex, visited);
        }
        current = current->next;
    }
}

/* Breadth-first search */
void bfs(Graph* graph, int v, int* visited)
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
                queue[rear++] = adjacentVertex;
            }
            adjacentNode = adjacentNode->next;
        }
    }

    free(queue);
}

void dfsFirstPass(Graph* graph, int vertex, int* visited, LinkedList* stack)
{
    visited[vertex] = 1;

    Node* current = graph->adjacencyList[vertex].header;
    while (current != NULL)
    {
        int adjacentVertex = current->item;
        if (!visited[adjacentVertex])
        {
            dfsFirstPass(graph, adjacentVertex, visited, stack);
        }
        current = current->next;
    }

    Node* newNode = createNode(vertex);
    newNode->next = stack->header;
    stack->header = newNode;
}

void stronglyConnectedComponents(Graph* graph)
{
    int vertices = graph->vertices;
    int* visited = (int*)calloc(vertices, sizeof(int));
    LinkedList* stack = (LinkedList*)malloc(sizeof(LinkedList));
    stack->header = NULL;

    // Primeira passagem: Busca em profundidade no grafo original
    for (int v = 0; v < vertices; v++)
    {
        if (!visited[v])
        {
            dfsFirstPass(graph, v, visited, stack);
        }
    }

    // Grafo reverso
    Graph* reversedGraph = reverseGraph(graph);

    // Segunda passagem: Busca em profundidade no grafo reverso
    memset(visited, 0, vertices * sizeof(int)); // Resetando o vetor visited

    while (stack->header != NULL)
    {
        int vertex = stack->header->item;
        stack->header = stack->header->next;

        if (!visited[vertex])
        {
            printf("Component: ");
            dfs(reversedGraph, vertex, visited);
            printf("\n");
        }
    }

    free(stack);
    free(visited);
    destroyGraph(reversedGraph);
}


int main()
{
    /* Graph */
    Graph* graph = createGraph(13);

    addEdge(graph, 1, 0);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 5);
    addEdge(graph, 5, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 4, 6);
    addEdge(graph, 6, 0);
    addEdge(graph, 7, 8);
    addEdge(graph, 9, 12);
    addEdge(graph, 10, 9);
    addEdge(graph, 11, 9);
    addEdge(graph, 12, 11);

    printf("Graph:\n");
    printGraph(graph);

    printf("\n%d vertices, %d edges\n", graph->vertices, graph->edges);

    /* Visited */
    int dfsVisited[13];
    memset(dfsVisited, 0, sizeof(dfsVisited));

    int bfsVisited[13];
    memset(bfsVisited, 0, sizeof(bfsVisited));

    /* Traversal */
    printf("\nDFS Traversal:\n");
    dfs(graph, 1, dfsVisited);

    printf("\n\nBFS Traversal:\n");
    bfs(graph, 1, bfsVisited);

    /* Reverse Graph */
    Graph* reversedGraph = reverseGraph(graph);
    printf("\nReversed Graph:\n");
    printGraph(reversedGraph);


    int vertex = 9;
    int degree = getDegree(graph, vertex);
    printf("\nDegree of vertex %d: %d\n", vertex, degree);

    printf("\nStrongly Connected Components:\n");
    stronglyConnectedComponents(graph);


    destroyGraph(graph);
    return 0;
}
