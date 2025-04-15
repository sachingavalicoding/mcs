#include <stdio.h>
#define N 4  // Size of the board (4x4)

int board[N][N];

// Function to print the board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if placing a queen at (row, col) is safe
int isSafe(int row, int col) {
    // Check the column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;  // Queen is already placed in the same column
        }
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;  // Queen is already placed in the upper-left diagonal
        }
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return 0;  // Queen is already placed in the upper-right diagonal
        }
    }

    return 1;  // Position is safe
}

// Backtracking function to solve the N Queens problem
int solveNQueens(int row) {
    // If all queens are placed
    if (row == N) {
        return 1;  // Solution found
    }

    // Try placing the queen in each column of the current row
    for (int col = 0; col < N; col++) {
        // Check if placing a queen at (row, col) is safe
        if (isSafe(row, col)) {
            board[row][col] = 1;  // Place the queen

            // Recur to place the next queen
            if (solveNQueens(row + 1)) {
                return 1;  // Solution found
            }

            // If placing queen doesn't lead to a solution, backtrack
            board[row][col] = 0;  // Remove the queen
        }
    }

    return 0;  // No solution found for this row
}

int main() {
    // Initialize the board with 0 (no queen placed)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Call the backtracking function to solve the problem
    if (solveNQueens(0)) {
        printf("Solution found:\n");
        printBoard();  // Print the board with queens placed
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
