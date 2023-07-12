#include <stdio.h>
#include <stdlib.h>

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

/* Queue */
typedef struct Queue
{
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue()
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue* queue, int item)
{
    Node* node = createNode(item);
    if (queue->rear == NULL)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
}

int dequeue(Queue* queue)
{
    if (queue->front == NULL)
    {
        return -1;
    }
    int item = queue->front->item;
    Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    return item;
}

/* Undirected Graph */
typedef struct Graph
{
    int vertex;
    int edge;
    LinkedList* adjacentVertices;
} Graph;

Graph* createGraph(int verticesNumber)
{
    if (verticesNumber <= 0)
    {
        return NULL;
    }
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertex = verticesNumber;
    graph->edge = 0;
    graph->adjacentVertices = (LinkedList*)malloc(verticesNumber * sizeof(LinkedList));
    /*Initializes the graph with NULL*/
    for (int v = 0; v < verticesNumber; v++)
    {
        graph->adjacentVertices[v].header = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int vertexV, int vertexW)
{
    if (graph == NULL || vertexV < 0 || vertexW < 0 || vertexV >= graph->vertex || vertexW >= graph->vertex)
    {
        return;
    }
    graph->edge++;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = vertexW;
    newNode->next = graph->adjacentVertices[vertexV].header;
    graph->adjacentVertices[vertexV].header = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->item = vertexV;
    newNode->next = graph->adjacentVertices[vertexW].header;
    graph->adjacentVertices[vertexW].header = newNode;
}

void printGraph(Graph* graph)
{
    for (int v = 0; v < graph->vertex; v++)
    {
        printf("%d: ", v);
        Node* current = graph->adjacentVertices[v].header;
        while (current != NULL)
        {
            printf("%d ", current->item);
            current = current->next;
        }
        printf("\n");
    }
}

/* Depth first search */
void dfs(Graph* graph, int vertex, int* marked)
{
    marked[vertex] = 1;
    printf("%d ", vertex);
    Node* current = graph->adjacentVertices[vertex].header;
    while (current != NULL)
    {
        int adjacentVertex = current->item;
        if (!marked[adjacentVertex])
        {
            dfs(graph, adjacentVertex, marked);
        }
        current = current->next;
    }
}

/* Breadth first search */
void bfs(Graph* graph, int startVertex, int* visited)
{
    Queue* queue = createQueue();
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!queue->front == NULL)
    {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* adjacentNode = graph->adjacentVertices[currentVertex].header;
        while (adjacentNode != NULL)
        {
            int adjacentVertex = adjacentNode->item;
            if (visited[adjacentVertex] == 0)
            {
                visited[adjacentVertex] = 1;
                enqueue(queue, adjacentVertex);
            }
            adjacentNode = adjacentNode->next;
        }
    }
    free(queue);
}

void destroyGraph(Graph* graph)
{
    if (graph == NULL)
    {
        return;
    }
    for (int v = 0; v < graph->vertex; v++)
    {
        Node* current = graph->adjacentVertices[v].header;
        while (current != NULL)
        {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adjacentVertices);
    free(graph);
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

    dfs(graph, 1, markedDFS);
    printf("\n");
    bfs(graph, 1, markedBFS);

    printf("\n%d vertices, %d arestas\n", graph->vertex, graph->edge);
    // Destruindo o grafo
    destroyGraph(graph);
    return 0;
}
