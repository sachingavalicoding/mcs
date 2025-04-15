#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for the linked list node
typedef struct Node {
    int i, j;        // Indices representing the range of keys
    int cost;        // Minimum cost for this subproblem
    int root;        // Root of the optimal BST for this subproblem
    struct Node* next; // Pointer to the next node in the linked list
} Node;

// Function to create a new node
Node* createNode(int i, int j, int cost, int root) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->i = i;
    newNode->j = j;
    newNode->cost = cost;
    newNode->root = root;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(Node** head, int i, int j, int cost, int root) {
    Node* newNode = createNode(i, j, cost, root);
    newNode->next = *head;
    *head = newNode;
}

// Function to get the cost for a given i, j from the linked list
int getCost(Node* head, int i, int j) {
    while (head != NULL) {
        if (head->i == i && head->j == j) {
            return head->cost;
        }
        head = head->next;
    }
    return -1;  // Return -1 if not found
}

// Function to get the root for a given i, j from the linked list
int getRoot(Node* head, int i, int j) {
    while (head != NULL) {
        if (head->i == i && head->j == j) {
            return head->root;
        }
        head = head->next;
    }
    return -1;  // Return -1 if not found
}

// Function to compute the sum of frequencies between i and j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++) {
        s += freq[k];
    }
    return s;
}

// Function to construct the optimal binary search tree
void optimalBST(int keys[], int freq[], int n) {
    Node* costList = NULL;  // Linked list to store costs and roots

    // Initialize the cost for one key as its frequency
    for (int i = 0; i < n; i++) {
        addNode(&costList, i, i, freq[i], i);
    }

    // Fill the cost list for multiple keys
    for (int length = 2; length <= n; length++) {  // length of the subproblem
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            int minCost = INT_MAX;
            int bestRoot = -1;

            // Try every key in the range [i, j] as root
            for (int r = i; r <= j; r++) {
                // Calculate the cost of the left and right subtrees
                int left_cost = (r > i) ? getCost(costList, i, r - 1) : 0;
                int right_cost = (r < j) ? getCost(costList, r + 1, j) : 0;

                // Total cost is the sum of the left and right subtrees plus the sum of all frequencies
                int total_cost = left_cost + right_cost + sum(freq, i, j);

                // If this cost is smaller, update the cost list and root
                if (total_cost < minCost) {
                    minCost = total_cost;
                    bestRoot = r;
                }
            }

            // Store the minimum cost and best root in the linked list
            addNode(&costList, i, j, minCost, bestRoot);
        }
    }

    // Output the minimum cost of the optimal binary search tree
    printf("The minimum cost of the optimal binary search tree is: %d\n", getCost(costList, 0, n - 1));
    
    // Optionally, print the roots of the optimal subtrees
    printf("The roots of the subtrees are:\n");
    for (int i = 0; i < n; i++) {
        printf("Root of subtree [%d, %d]: %d\n", i, i, getRoot(costList, i, i));
    }
}

// Driver function
int main() {
    int n;
    
    // Input number of keys
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n];

    // Input keys and their respective frequencies
    printf("Enter the keys: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &keys[i]);
    }

    printf("Enter the frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &freq[i]);
    }

    // Call the function to compute the optimal BST
    optimalBST(keys, freq, n);

    return 0;
}
