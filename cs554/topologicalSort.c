#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Define the structure of the graph
struct Graph {
    int vertices;
    int adj[MAX][MAX]; // Adjacency matrix
};

// Function to perform Topological Sorting using Kahn's Algorithm
void topologicalSort(struct Graph *graph) {
    int in_degree[MAX] = {0}; // Initialize in-degree of all vertices to 0
    int queue[MAX], front = 0, rear = 0;
    
    // Calculate in-degree for each vertex
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->adj[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < graph->vertices; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;  // Count of vertices processed
    int top_order[MAX]; // To store the topological order

    // Process the graph
    while (front < rear) {
        int u = queue[front++];  // Dequeue a vertex
        top_order[count++] = u;  // Add to the topological order

        // Update in-degree of all its neighbors
        for (int v = 0; v < graph->vertices; v++) {
            if (graph->adj[u][v] == 1) {
                if (--in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // If count doesn't match vertices, there is a cycle
    if (count != graph->vertices) {
        printf("There exists a cycle in the graph. Topological sort is not possible.\n");
        return;
    }

    // Print the topological order
    printf("Topological Sort: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", top_order[i]);
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    int edges, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &graph.vertices);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < graph.vertices; i++) {
        for (int j = 0; j < graph.vertices; j++) {
            graph.adj[i][j] = 0;
        }
    }

    // Input edges for the graph
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (u v) where there is an edge from u to v:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph.adj[u][v] = 1;  // Set the adjacency matrix entry to 1 for an edge u -> v
    }

    // Perform topological sort
    topologicalSort(&graph);

    return 0;
}
