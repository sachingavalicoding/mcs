#include <stdio.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;         // Job ID
    int deadline;   // Deadline of the job
    int profit;     // Profit of the job
};

// Function to compare two jobs based on their profit
int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Function to find the maximum profit job sequence
void jobSequencing(struct Job jobs[], int n) {
    // Sort jobs in decreasing order of profit
    qsort(jobs, n, sizeof(struct Job), compare);

    // Array to keep track of free time slots
    int result[n];  // To store the sequence of jobs
    int slot[n];    // To store whether a slot is occupied (1 for occupied, 0 for empty)

    // Initialize all slots as empty
    for (int i = 0; i < n; i++) {
        slot[i] = 0;
    }

    // To store the total profit
    int totalProfit = 0;

    // Iterate through all jobs
    for (int i = 0; i < n; i++) {
        // Find a free slot for the current job (starting from the last possible slot)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            // If the slot is empty, schedule the job
            if (slot[j] == 0) {
                result[j] = jobs[i].id;
                slot[j] = 1;  // Mark this slot as occupied
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output the result
    printf("Job sequence that yields maximum profit:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i] == 1) {
            printf("Job %d ", result[i]);
        }
    }
    printf("\nTotal Profit = %d\n", totalProfit);
}

int main() {
    // Array of jobs, each having id, deadline, and profit
    struct Job jobs[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Function call to find the job sequence with maximum profit
    jobSequencing(jobs, n);

    return 0;
}
