#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,vector<vector<int>>& grid){
    if(i == 0 && j == 0)return grid[0][0];
    if(i<0 || j<0) return INT_MAX;//return so big this path is rejected

    int up = grid[i][j] + f(i-1,j,grid);//take the current grid in sum and move up
    int left = grid[i][j] + f(i,j-1,grid);

    return min(up , left);
}//as go from end to start so up and left and from start we could move to down and right

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return f(n-1,m-1,grid);
    }


//memoization

int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
    if(i == 0 && j == 0)return grid[0][0];
    if(i<0 || j<0) return 1e9;//return so big this path is rejected
    if(dp[i][j] != -1) return dp[i][j];
    int up = grid[i][j] + f(i-1,j,grid,dp);//take the current grid in sum and move up
    int left = grid[i][j] + f(i,j-1,grid,dp);

    return dp[i][j] =min(up , left);
}

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
}

//tabulation
//0 to n-1 and 0 to m-1 go 

int minPathSum( vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[0][0];
            }
            else{
                int up = 1e9;
                int left = 1e9;

                if(i>0){
                    up = grid[i][j] + dp[i-1][j];
                }
                if(j>0){
                    left = grid[i][j] + dp[i][j-1];
                }
                dp[i][j] = min(up , left);
            }
        }
    }
    return dp[n-1][m-1];
}


//space optimization

int minPathSum( vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    vector<int>prev(m,0);
    for(int i=0;i<n;i++){
        vector<int> curr(m,0);
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0){
                curr[j] = grid[0][0];
            }
            else{
                int up = 1e9;
                int left = 1e9;

                if(i>0){//prev rows jth coloum
                    up = grid[i][j] + prev[j];
                }
                if(j>0){//current rows j-1 coloum
                    left = grid[i][j] + curr[j-1];
                }
                curr[j] = min(up , left);
            }
        }
        prev = curr;
    }
    return prev[m-1];//when loop end prev has all the values of last row
}

