#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item in the knapsack problem
struct Item {
    int weight;  // Weight of the item
    int value;   // Value of the item
    float ratio; // Value-to-weight ratio of the item
};

// Function to compare two items based on their value-to-weight ratio
// This function is used by qsort to sort the items in decreasing order of ratio
int compare(const void *a, const void *b) {
    // Convert void pointers to Item pointers to access weight, value, and ratio
    float r1 = ((struct Item *)a)->ratio; // Get the ratio of the first item
    float r2 = ((struct Item *)b)->ratio; // Get the ratio of the second item

    // Return a positive value if r1 < r2, negative if r1 > r2, and 0 if equal
    return (r1 < r2) - (r1 > r2);
}

// Function to solve the Knapsack problem using the Greedy method
float knapsackGreedy(struct Item items[], int n, int capacity) {
    // Sort the items in decreasing order of value-to-weight ratio
    qsort(items, n, sizeof(struct Item), compare);  // Sorting function

    int totalWeight = 0;  // Variable to keep track of the current total weight in the knapsack
    float totalValue = 0.0; // Variable to keep track of the total value in the knapsack

    // Iterate through the sorted items and select them for the knapsack
    for (int i = 0; i < n; i++) {
        // If the item can fit entirely in the knapsack
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;          // Add the whole item to the knapsack
            totalValue += items[i].value;           // Add the value of the item
        } else {
            // If the item can't fit entirely, take the fraction that fits
            int remainingWeight = capacity - totalWeight;  // Calculate remaining capacity in knapsack
            totalValue += items[i].value * ((float)remainingWeight / items[i].weight); // Add the fractional value
            break;  // The knapsack is full, break the loop
        }
    }

    return totalValue; // Return the total value of the items in the knapsack
}

int main() {
    int n, capacity;
    
    // Input the number of items and the capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];  // Declare an array of items

    // Input the weight and value of each item
    for (int i = 0; i < n; i++) {
        printf("Enter the weight and value of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].value);

        // Calculate the value-to-weight ratio for each item
        items[i].ratio = (float)items[i].value / items[i].weight;
    }

    // Solve the knapsack problem using the Greedy method
    float maxValue = knapsackGreedy(items, n, capacity);

    // Output the result: maximum value that can be obtained with the given knapsack capacity
    printf("The maximum value that can be obtained is: %.2f\n", maxValue);

    return 0;
}
