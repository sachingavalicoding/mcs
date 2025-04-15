#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // pivot
    int i = (low - 1);      // index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random numbers
    srand(time(NULL)); // Seed random generator
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generate numbers between 0 and 9999
    }

    // Start time
    clock_t start = clock();

    // Call Quick Sort
    quickSort(arr, 0, n - 1);

    // End time
    clock_t end = clock();

    // Calculate time in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print sorted array (optional for large n)
    if (n <= 100) {
        printf("Sorted array:\n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    return 0;
}
