#include <stdio.h>
#include <stdlib.h>

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
void bfs(Graph* graph, int v, int* marked)
{
    int vertices = graph->vertices;
    int* queue = (int*)malloc(vertices * sizeof(int));
    int front = 0;
    int rear = 0;

    marked[v] = 1;
    queue[rear++] = v;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        Node* adjacentNode = graph->adjacencyList[currentVertex].header;
        while (adjacentNode != NULL)
        {
            int adjacentVertex = adjacentNode->item;
            if (marked[adjacentVertex] == 0)
            {
                marked[adjacentVertex] = 1;
                queue[rear++] = adjacentVertex;
            }
            adjacentNode = adjacentNode->next;
        }
    }

    free(queue);
}


int main()
{
    // Criando um grafo com 5 vértices
    Graph* graph = createGraph(13);

    int markedDFS[13];
    memset(markedDFS, 0, sizeof(markedDFS));

    int markedBFS[13];
    memset(markedBFS, 0, sizeof(markedBFS));

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

    // Imprimindo o grafo
    printGraph(graph);

    printf("DFS:\n");
    dfs(graph, 1, markedDFS);
    printf("\nBFS:\n");
    bfs(graph, 1, markedBFS);

    printf("\n%d vertices, %d arestas\n", graph->vertices, graph->edges);
    // Destruindo o grafo
    destroyGraph(graph);
    return 0;
}
