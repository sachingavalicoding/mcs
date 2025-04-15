#include <stdio.h>

// Function to add two matrices A and B, and store the result in matrix C
// It loops through each element of matrices A and B and adds the corresponding elements.
void add(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract matrix B from matrix A, and store the result in matrix C
// It loops through each element of matrices A and B and subtracts the corresponding elements.
void subtract(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Strassen's algorithm for matrix multiplication
// This function multiplies two 2x2 matrices A and B using Strassen’s method
// It calculates 7 intermediary products (M1 to M7) and then uses them to compute the final product.
void strassen(int A[2][2], int B[2][2], int C[2][2]) {
    // Declaring 7 intermediary variables (M1 to M7) for storing the results of intermediate multiplications.
    int M1, M2, M3, M4, M5, M6, M7;

    // Compute the 7 products as per Strassen's algorithm
    M1 = A[0][0] * (B[0][1] - B[1][1]);  // First intermediary product (M1)
    M2 = (A[0][0] + A[0][1]) * B[1][1];  // Second intermediary product (M2)
    M3 = (A[1][0] + A[1][1]) * B[0][0];  // Third intermediary product (M3)
    M4 = A[1][1] * (B[1][0] - B[0][0]);  // Fourth intermediary product (M4)
    M5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);  // Fifth intermediary product (M5)
    M6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);  // Sixth intermediary product (M6)
    M7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);  // Seventh intermediary product (M7)

    // Calculate the result matrix C using the intermediary products (M1 to M7)
    C[0][0] = M5 + M4 - M2 + M6;  // First element of the result matrix
    C[0][1] = M1 + M2;  // Second element of the result matrix
    C[1][0] = M3 + M4;  // Third element of the result matrix
    C[1][1] = M5 + M1 - M3 - M7;  // Fourth element of the result matrix
}

// Function to print the 2x2 matrix C
// It prints each element of the matrix on the screen in a readable format.
void printMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");  // Print a newline after each row of the matrix
    }
}

int main() {
    // Declaring matrices A, B, and C
    // A and B are input matrices, and C is the result matrix of the multiplication
    int A[2][2], B[2][2], C[2][2];

    // Taking input for matrix A (2x2)
    printf("Enter elements of matrix A (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);  // Reading each element of matrix A
        }
    }

    // Taking input for matrix B (2x2)
    printf("Enter elements of matrix B (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);  // Reading each element of matrix B
        }
    }

    // Call the Strassen's matrix multiplication function
    // This function will calculate the matrix product and store the result in matrix C
    strassen(A, B, C);

    // Output the result
    printf("Product of matrices A and B using Strassen's method is:\n");
    printMatrix(C);  // Print the result matrix C

    return 0;  // End of the program
}
