#include <stdio.h>
#include <string.h>

// Function to find the length of Longest Common Subsequence (LCS)
int LCSLength(char* X, char* Y) {
    int m = strlen(X); // Length of string X
    int n = strlen(Y); // Length of string Y
    
    // Create a 2D table to store lengths of longest common subsequence
    int dp[m+1][n+1];
    
    // Build the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0; // Base case: if any string is empty, LCS is 0
            } else if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1; // If characters match
            } else {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1]; // Otherwise, take the max of previous results
            }
        }
    }
    
    // The length of LCS will be at the bottom-right corner of the matrix
    return dp[m][n];
}

int main() {
    char X[] = "AGGTAB"; // First string
    char Y[] = "GXTXAYB"; // Second string
    
    // Call the function and display the result
    int lcsLength = LCSLength(X, Y);
    printf("Length of Longest Common Subsequence: %d\n", lcsLength);
    
    return 0;
}
