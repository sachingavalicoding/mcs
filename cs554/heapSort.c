#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function to maintain the heap property
void heapify(int arr[], int n, int i) {
    int largest = i;      // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to implement heapsort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements from heap
    for (int i = n - 1; i >= 1; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0); // Call heapify on the reduced heap
    }
}

int main() {
    int n, i;

    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random numbers for the array
    srand(time(NULL)); // Seed the random number generator
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Generate numbers between 0 and 9999
    }

    // Record start time
    clock_t start = clock();

    // Perform Heapsort
    heapSort(arr, n);

    // Record end time
    clock_t end = clock();

    // Calculate time taken in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print sorted array (optional for small n)
    if (n <= 100) {
        printf("Sorted array:\n");
        for (i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }

    // Print time taken
    printf("Time taken to sort %d elements using Heapsort: %f seconds\n", n, time_taken);

    return 0;
}
