#include<stdio.h>
#include<stdlib.h>

// Create an adjacency list representation of a graph
struct Graph {
    int V;
    int** E;
};

// Function to allocate memory for an adjacency list
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = (int**) malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->E[i] = (int*) malloc(V * sizeof(int));
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->E[src][dest] = 1;
}

// Function to perform DFS on the graph starting from a given vertex
void DFS(struct Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < graph->V; i++) {
        if (graph->E[v][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

// Function to perform DFS on the graph
void performDFS(struct Graph* graph) {
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    struct Graph* graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    performDFS(graph);
    return 0;
}