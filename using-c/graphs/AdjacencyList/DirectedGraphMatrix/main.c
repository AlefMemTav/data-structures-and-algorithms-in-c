#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
    int vertices;
    int** adjacencyMatrix;
} Graph;

Graph* createGraph(int vertices)
{
    if (vertices <= 0)
    {
        return NULL;
    }

    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;

    // Alocar memória para a matriz de adjacência
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }

    return graph;
}

void addEdge(Graph* graph, int from, int to)
{
    if (graph == NULL || from < 0 || to < 0 || from >= graph->vertices || to >= graph->vertices)
    {
        return;
    }

    graph->adjacencyMatrix[from][to] = 1;
}

void printGraph(Graph* graph)
{
    if (graph == NULL)
    {
        return;
    }

    int vertices = graph->vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", graph->adjacencyMatrix[i][j]);
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

    int vertices = graph->vertices;
    for (int i = 0; i < vertices; i++)
    {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main()
{
    int vertices = 13;
    Graph* graph = createGraph(vertices);

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

    printGraph(graph);

    destroyGraph(graph);

    return 0;
}
