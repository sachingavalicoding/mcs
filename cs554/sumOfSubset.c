#include <stdio.h>

// Function to print the current subset
void printSubset(int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Backtracking function to find the subsets whose sum equals the target
void findSubsetSum(int arr[], int n, int target, int index, int subset[], int subsetSize) {
    // If we reached the end of the array
    if (index == n) {
        // If the sum of the current subset equals the target, print it
        int sum = 0;
        for (int i = 0; i < subsetSize; i++) {
            sum += subset[i];
        }
        if (sum == target) {
            printSubset(subset, subsetSize);
        }
        return;
    }
    
    // Include the current element in the subset and move to the next element
    subset[subsetSize] = arr[index];
    findSubsetSum(arr, n, target, index + 1, subset, subsetSize + 1);
    
    // Exclude the current element from the subset and move to the next element
    findSubsetSum(arr, n, target, index + 1, subset, subsetSize);
}

// Driver function
int main() {
    int n, target;
    
    // Input number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the set
    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);
    
    int subset[n]; // Array to store the current subset
    printf("The subsets whose sum equals %d are:\n", target);
    
    // Call the function to find subsets
    findSubsetSum(arr, n, target, 0, subset, 0);
    
    return 0;
}
