#include <stdio.h>
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

void addEdge(Graph* graph, int v, int w)
{
    if (graph == NULL || v < 0 || w < 0 || v >= graph->vertices || w >= graph->vertices)
    {
        return;
    }

    graph->adjacencyMatrix[v][w] = 1;
    graph->adjacencyMatrix[w][v] = 1;
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

// Depth-First Search (DFS)
void dfs(Graph* graph, int vertex, int* visited)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    int vertices = graph->vertices;
    for (int i = 0; i < vertices; i++)
    {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i])
        {
            dfs(graph, i, visited);
        }
    }
}

// Breadth-First Search (BFS)
void bfs(Graph* graph, int startVertex, int* visited)
{
    int vertices = graph->vertices;

    // Criar fila para armazenar vértices a serem visitados
    int* queue = (int*)malloc(vertices * sizeof(int));
    int front = 0;
    int rear = 0;

    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        for (int i = 0; i < vertices; i++)
        {
            if (graph->adjacencyMatrix[currentVertex][i] && !visited[i])
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    free(queue);
}

int main()
{
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printf("DFS: ");
    int* visitedDFS = (int*)calloc(vertices, sizeof(int));
    dfs(graph, 0, visitedDFS);
    free(visitedDFS);
    printf("\n");

    printf("BFS: ");
    int* visitedBFS = (int*)calloc(vertices, sizeof(int));
    bfs(graph, 0, visitedBFS);
    free(visitedBFS);
    printf("\n");

    destroyGraph(graph);

    return 0;
}
