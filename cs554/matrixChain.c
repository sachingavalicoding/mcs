#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of multiplications
int matrixChainOrder(int p[], int n) {
    // dp[i][j] will store the minimum number of multiplications required to multiply matrices i to j
    int dp[n][n];

    // Base case: A single matrix requires 0 multiplications
    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    // Fill the dp table in a bottom-up manner
    for (int length = 2; length < n; length++) {
        for (int i = 1; i < n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX; // Initialize with a large number

            // Try all possible places to split the chain
            for (int k = i; k < j; k++) {
                int q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < dp[i][j]) {
                    dp[i][j] = q;
                }
            }
        }
    }

    // The result is the minimum cost for multiplying matrices 1 to n-1
    return dp[1][n - 1];
}

int main() {
    // Define the dimensions of matrices in the form (rows x columns)
    // p[i-1] x p[i] is the dimension of the i-th matrix
    int p[] = {1, 2, 3, 4, 5}; // Matrices are 1x2, 2x3, 3x4, 4x5
    int n = sizeof(p) / sizeof(p[0]);

    // Function call to get the minimum number of multiplications
    int result = matrixChainOrder(p, n);

    printf("Minimum number of multiplications is %d\n", result);

    return 0;
}
