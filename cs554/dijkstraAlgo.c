#include <stdio.h>
#include <limits.h>  // For INT_MAX

#define V 9  // Number of vertices in the graph

// Function to find the vertex with the minimum distance
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    
    // Find the vertex with the smallest tentative distance
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // The output array, dist[i] holds the shortest distance from src to i
    int sptSet[V]; // sptSet[i] will be 1 if vertex i is included in the shortest path tree, else 0
    
    // Initialize all distances as infinity and sptSet[] as 0
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i
