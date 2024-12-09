#include <stdio.h>
#define MAX 3 // Use consistent capitalization for constants

void breadth(int arr[][MAX], int visited[], int start) {
    int queue[10], front = -1, rear = -1, i;

    // Enqueue the starting vertex
    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        // Dequeue a vertex
        start = queue[++front];

        // Print the current vertex (special case for vertex 4)
        
            printf("%c\t", start + 65); // Convert index to character (A, B, ...)
        }

        // Explore all adjacent vertices
        for (i = 0; i < MAX; i++) {
            if (arr[start][i] == 1 && visited[i] == 0) {
                queue[++rear] = i; // Enqueue adjacent vertex
                visited[i] = 1;    // Mark as visited
            }
        }
    }


int main() {
    int visited[MAX] = {0}; // Initialize the visited array
    int adj[MAX][MAX], i, j;

    printf("\nEnter the adjacency matrix (%dx%d):\n", MAX, MAX);
    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            scanf("%d", &adj[i][j]); // Correct variable name here
        }
    }

    int start;
    printf("\nEnter the starting vertex (0-%d): ", MAX - 1);
    scanf("%d", &start);

    printf("\nBreadth-First Traversal starting from vertex %c:\n", start + 65);
    breadth(adj, visited, start);

    return 0;
}
