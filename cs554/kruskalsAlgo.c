#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;  // Source, destination, and weight of the edge
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges based on their weight
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Find function for Union-Find (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent); // Path compression
    }
    return subsets[i].parent;
}

// Union function for Union-Find (by rank)
void unionSets(struct Subset subsets[], int xroot, int yroot) {
    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot; // Make yroot as parent
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot; // Make xroot as parent
    } else {
        subsets[yroot].parent = xroot;  // Make xroot as parent and increase rank
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's Algorithm to find MST
void kruskal(struct Edge edges[], int V, int E) {
    // Sort all the edges in non-decreasing order of their weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Create V subsets (one for each vertex)
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));

    // Initialize each subset with itself as the parent and rank as 0
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // To store the resultant MST
    struct Edge result[V - 1]; 
    int e = 0;  // Count of edges in MST

    // Iterate through sorted edges and process them
    for (int i = 0; i < E && e < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        // If including this edge doesn't form a cycle
        if (x != y) {
            result[e++] = edges[i];  // Include this edge in MST
            unionSets(subsets, x, y);  // Union of two subsets
        }
    }

    // Output the MST
    printf("Edges in the Minimum Spanning Tree (MST):\n");
    for (int i = 0; i < e; i++) {
        printf("%d - %d: %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(subsets);
}

int main() {
    int V, E;
    
    // Input the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Edge edges[E];

    // Input all the edges and their weights
    printf("Enter the edges (source, destination, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    // Call Kruskal's algorithm to find the MST
    kruskal(edges, V, E);

    return 0;
}
