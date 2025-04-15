#include <stdio.h>
#include <stdbool.h>

#define V 5

// Function to print the cycle
void printSolution(int path[]) {
    printf("Hamiltonian Cycle Found:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Print starting vertex again to show cycle
}

// Check if vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, bool graph[V][V], int path[], int pos) {
    // Check if current vertex and last vertex in path are adjacent
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if vertex has already been included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive utility function
bool hamCycleUtil(bool graph[V][V], int path[], int pos) {
    if (pos == V) {
        // If there is an edge from last vertex to the first
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    // Try different vertices as the next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1) == true)
                return true;

            path[pos] = -1; // Backtrack
        }
    }

    return false;
}

// Main function to solve the problem
bool hamCycle(bool graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    // Start from vertex 0
    path[0] = 0;

    if (hamCycleUtil(graph, path, 1) == false) {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    // Example graph
    bool graph1[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    hamCycle(graph1);

    return 0;
}
