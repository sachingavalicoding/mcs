#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;

    // Search for the vertex with the minimum key value
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm to find MST
void primMST(int graph[V][V]) {
    int parent[V];   // Array to store the constructed MST
    int key[V];      // Key values used to pick minimum weight edge
    int mstSet[V];   // To represent vertices included in MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // First vertex is picked as the root of the MST
    key[0] = 0;  // Make key of first vertex 0
    parent[0] = -1; // The root does not have a parent

    // Construct MST one by one
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex that is not yet included in the MST
        int u = minKey(key, mstSet);

        // Include the picked vertex in MST
        mstSet[u] = 1;

        // Update the key values of adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // If v is not in MST and there is an edge from u to v
            // and the weight of edge u-v is smaller than the current key value of v
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print the MST
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Call the function to find the MST
    primMST(graph);

    return 0;
}
