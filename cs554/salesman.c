#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

// Function to calculate the distance between two cities
int calculateDistance(int city1, int city2, int distanceMatrix[MAX][MAX]) {
    return distanceMatrix[city1][city2];
}

// Function to find the nearest unvisited city
int nearestNeighbor(int currentCity, int visited[MAX], int distanceMatrix[MAX][MAX], int numCities) {
    int minDistance = INT_MAX;
    int nextCity = -1;
    
    for (int i = 0; i < numCities; i++) {
        if (!visited[i] && i != currentCity) {
            int distance = calculateDistance(currentCity, i, distanceMatrix);
            if (distance < minDistance) {
                minDistance = distance;
                nextCity = i;
            }
        }
    }
    
    return nextCity;
}

// Function to implement the nearest neighbor algorithm for TSP
void nearestNeighborTSP(int distanceMatrix[MAX][MAX], int numCities) {
    int visited[MAX] = {0}; // Array to track visited cities
    int tour[MAX]; // Array to store the tour
    int totalDistance = 0;
    int currentCity = 0; // Start from city 0

    visited[currentCity] = 1;
    tour[0] = currentCity;
    
    printf("Tour Order: ");
    for (int i = 1; i < numCities; i++) {
        int nextCity = nearestNeighbor(currentCity, visited, distanceMatrix, numCities);
        visited[nextCity] = 1;
        tour[i] = nextCity;
        totalDistance += calculateDistance(currentCity, nextCity, distanceMatrix);
        currentCity = nextCity;
    }
    
    // Add the distance to return to the start city
    totalDistance += calculateDistance(currentCity, tour[0], distanceMatrix);
    
    // Print the result
    for (int i = 0; i < numCities; i++) {
        printf("%d ", tour[i]);
    }
    printf("\nTotal Distance: %d\n", totalDistance);
}

int main() {
    int numCities;
    int distanceMatrix[MAX][MAX];

    // Input number of cities
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);
    
    // Input the distance matrix
    printf("Enter the distance matrix (use -1 for no direct path between cities):\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &distanceMatrix[i][j]);
        }
    }

    // Call the nearest neighbor algorithm
    nearestNeighborTSP(distanceMatrix, numCities);

    return 0;
}
