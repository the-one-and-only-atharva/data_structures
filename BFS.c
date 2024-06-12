#include <stdio.h>
#include <stdlib.h>

// This array represents the graph. 
// If there is a direct connection from 'i' to 'j', value at index 'j' in array 'i' is 1.
// If there is no direct connection from 'i' to 'j', value at index 'j' in array 'i' is 0.

int graph[6][6] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0, 0},
    {0, 1, 1, 0, 1, 0},
    {0, 0, 0, 1, 0, 1},
    {0, 0, 0, 0, 1, 0}
};

int n = sizeof(graph) / sizeof(graph[0]);

// This function implements BFS.
void bfs(int start) {
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int queue[n], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front != rear) {
        int s = queue[front++];
        printf("%d ", s);

        for (int i = 0; i < n; i++) {
            if (graph[s][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Breadth-First Search traversal of the graph using queue is:\n");
    bfs(0);
    return 0;
}