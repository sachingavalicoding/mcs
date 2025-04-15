/*
    Program: N-Queens Problem using Backtracking
    Description:
    The N-Queens problem is to place N chess queens on an N×N chessboard so that no two queens threaten each other.
    This means that no two queens share the same row, column, or diagonal.

    Logic:
    - We place one queen in each row.
    - For each row, we try all columns.
    - Before placing a queen, we check if it's safe (no other queen is in the same column or diagonal).
    - If it's safe, place it and move to the next row.
    - If we can't place a queen in any column, we backtrack.

    Method used: Backtracking
*/

#include <stdio.h>
#include <stdbool.h>

#define N 4  // You can change this value to any number (e.g., 8 for 8-Queens)

int board[N][N];

// Function to print the board
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place queen at board[row][col]
bool isSafe(int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Solve N Queens using Backtracking
bool solveNQueens(int row) {
    if (row == N) {
        printSolution(); // Print one of the solutions
        return true; // return true to continue finding all solutions
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            // Recursively place the rest of the queens
            res = solveNQueens(row + 1) || res;

            board[row][col] = 0; // Backtrack
        }
    }

    return res;
}

int main() {
    // Initialize the board with 0
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (!solveNQueens(0))
        printf("No solution exists for N = %d\n", N);

    return 0;
}
