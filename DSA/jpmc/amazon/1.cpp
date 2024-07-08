#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to solve the problem
int maxHCFPath(const vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    
    // DP table to store the maximum HCF to reach each cell
    vector<vector<int>> dp(N, vector<int>(M, 0));
    
    // Initialize the starting point
    dp[0][0] = grid[0][0];
    
    // Fill the first row (can only come from the left)
    for (int j = 1; j < M; ++j) {
        dp[0][j] = gcd(dp[0][j - 1], grid[0][j]);
    }
    
    // Fill the first column (can only come from above)
    for (int i = 1; i < N; ++i) {
        dp[i][0] = gcd(dp[i - 1][0], grid[i][0]);
    }
    
    // Fill the rest of the dp table
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            int fromAbove = gcd(dp[i - 1][j], grid[i][j]);
            int fromLeft = gcd(dp[i][j - 1], grid[i][j]);
            dp[i][j] = max(fromAbove, fromLeft);
        }
    }
    
    // The bottom-right corner contains the answer
    return dp[N - 1][M - 1];
}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int result = maxHCFPath(grid);
    cout << result << endl;
    
    return 0;
}
