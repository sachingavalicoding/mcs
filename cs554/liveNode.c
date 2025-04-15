#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
bool visited[MAX];
int stack[MAX], top = -1;
int n;

// Push function for stack
void push(int node) {
    stack[++top] = node;
}

// Pop function for stack
int pop() {
    return stack[top--];
}

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// DFS to simulate node expansion
void findNodes(int start) {
    bool live[MAX] = { false };
    bool dead[MAX] = { false };

    push(start);
    live[start] = true;

    while (!isEmpty()) {
        int current = pop();
        visited[current] = true;

        printf("E-Node (Expanding): %d\n", current);
        live[current] = false;   // no longer live
        dead[current] = true;    // marked dead after expansion

        for (int i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i] && !live[i]) {
                push(i);
                live[i] = true;
                printf("Live Node generated: %d\n", i);
            }
        }
    }

    printf("\nDead Nodes: ");
    for (int i = 0; i < n; i++) {
        if (dead[i])
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    printf("Enter number of nodes in graph: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    int start;
    printf("Enter starting node (0 to n-1): ");
    scanf("%d", &start);

    printf("\nTraversal and Node Status:\n");
    findNodes(start);

    return 0;
}
