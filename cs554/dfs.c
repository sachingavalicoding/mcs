#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum number of vertices

// Node structure for the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    struct Node* adjList[MAX];
    int visited[MAX];
};

// Function to create a graph
void initGraph(struct Graph* graph) {
    for (int i = 0; i < MAX; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
}

// Function to add an edge in the graph (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src (undirected graph)
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS function using recursion
void DFS(struct Graph* graph, int vertex) {
    // Mark the current node as visited
    graph->visited[vertex] = 1;
    printf("%d ", vertex);  // Print the vertex

    // Explore all adjacent vertices of the current vertex
    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex);  // Recursively visit adjacent nodes
        }
        temp = temp->next;
    }
}

// Main function to demonstrate the DFS implementation
int main() {
    struct Graph graph;
    initGraph(&graph);

    // Adding edges to the graph
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);

    printf("Depth First Search starting from vertex 0:\n");
    DFS(&graph, 0);

    return 0;
}
