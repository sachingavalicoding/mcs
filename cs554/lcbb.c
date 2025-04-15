#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

// Structure for storing the items
struct Item {
    int weight;
    int value;
};

// Structure for storing node data during branch and bound
struct Node {
    int level;       // Level in the decision tree
    int profit;      // Profit in the current node
    int weight;      // Weight in the current node
    float bound;     // Upper bound of the profit
};

// Function to calculate the upper bound (bound) for the knapsack node
float calculateBound(struct Node u, int n, int W, struct Item items[]) {
    if (u.weight >= W) return 0;
    int profitBound = u.profit;
    int j = u.level + 1;
    int totalWeight = u.weight;

    // Consider the remaining items
    while (j < n && totalWeight + items[j].weight <= W) {
        totalWeight += items[j].weight;
        profitBound += items[j].value;
        j++;
    }

    // If there's still some weight left, take the fractional part of the next item
    if (j < n) {
        profitBound += (W - totalWeight) * (float)items[j].value / items[j].weight;
    }

    return profitBound;
}

// Function to implement the Least Cost Branch and Bound algorithm for 0/1 Knapsack
int knapsack(int W, struct Item items[], int n) {
    struct Node u, v;
    int maxProfit = 0;

    // Priority queue to store nodes, sorted by bound
    struct Node queue[MAX_ITEMS];
    int front = -1, rear = -1;

    // Initial node (level -1, no items in knapsack)
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = calculateBound(u, n, W, items);
    queue[++rear] = u;

    // Process the queue
    while (front != rear) {
        u = queue[++front];

        // If we have reached the last level, check the profit
        if (u.level == n - 1) continue;

        // Include the next item in the knapsack
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.profit = u.profit + items[v.level].value;

        // Check if this solution is feasible and has a bound greater than the current max profit
        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
        }

        // Calculate the bound for including the item
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) {
            queue[++rear] = v;  // Add to the queue if it is promising
        }

        // Exclude the next item from the knapsack
        v.level = u.level + 1;
        v.weight = u.weight;
        v.profit = u.profit;

        // Calculate the bound for excluding the item
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxProfit) {
            queue[++rear] = v;  // Add to the queue if it is promising
        }
    }

    return maxProfit;
}

int main() {
    int W = 50;  // Maximum weight capacity of the knapsack
    int n = 5;   // Number of items

    // Array of items (weight, value)
    struct Item items[] = {
        {10, 60},
        {20, 100},
        {30, 120},
        {40, 160},
        {50, 200}
    };

    int result = knapsack(W, items, n);
    printf("Maximum profit is: %d\n", result);

    return 0;
}
