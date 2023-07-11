#include <stdio.h>
#include <stdlib.h>

/* Linked List */
typedef struct Node
{
    int item;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* header;
} LinkedList;

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
    /*
    * Initializes the graph with NULL
    */
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

    // Adicionando algumas arestas
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

    printf("%d vertices, %d arestas\n", graph->vertex, graph->edge);

    // Destruindo o grafo
    destroyGraph(graph);
    return 0;
}
