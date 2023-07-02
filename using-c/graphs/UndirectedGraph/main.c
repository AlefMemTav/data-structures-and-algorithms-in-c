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
    Node* first;
} LinkedList;

/* Graph */
typedef struct Graph
{
    int V;
    int E;
    LinkedList* adj;
} Graph;

Graph* createGraph(int V)
{
    if (V < 0)
    {
        fprintf(stderr, "Number of vertices must be non-negative\n");
        exit(1);
    }
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->adj = (LinkedList*)malloc(V * sizeof(LinkedList));
    for (int v = 0; v < V; v++)
    {
        graph->adj[v].first = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int v, int w)
{
    validateVertex(graph, v);
    validateVertex(graph, w);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = w;
    newNode->next = graph->adj[v].first;
    graph->adj[v].first = newNode;

    newNode = (Node*)malloc(sizeof(Node));
    newNode->item = v;
    newNode->next = graph->adj[w].first;
    graph->adj[w].first = newNode;

    graph->E++;
}

void validateVertex(Graph* graph, int v)
{
    if (v < 0 || v >= graph->V)
    {
        fprintf(stderr, "Vertex %d is not between 0 and %d\n", v, graph->V - 1);
        exit(1);
    }
}

void printGraph(Graph* graph)
{
    printf("%d vertices, %d edges\n", graph->V, graph->E);
    for (int v = 0; v < graph->V; v++)
    {
        printf("%d: ", v);
        Node* current = graph->adj[v].first;
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
    for (int v = 0; v < graph->V; v++)
    {
        Node* current = graph->adj[v].first;
        while (current != NULL)
        {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }
    free(graph->adj);
    free(graph);
}

int main(int argc, char* argv[])
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

    // Destruindo o grafo
    destroyGraph(graph);
    return 0;
}
