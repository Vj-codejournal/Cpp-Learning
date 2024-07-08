int f(int i,int j){
    if(i == 0 && j == 0)return 1;
    if(i<0 || j<0) return 0;

    int up = f(i-1,j);
    int left = f(i,j-1);

    return up + left;
}
//TC - 2^(mxn) as at each grid 2 options
//SC - O(path length) = (m-1) + (n-1);


//DP Recurison Memoization
// can have a call for (0,0) (0,1) (0,2) (0,3) (1,0)(1,1) (1,2)....total mxn calls so O(mxn)
//SC - O(m-1) + O(n-1) + O(mxn)
#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>>& dp){
    if(i == 0 && j == 0)return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int up = f(i-1,j,dp);
    int left = f(i,j-1,dp);

    return dp[i][j] = up + left;

}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return f(m-1,n-1,dp);
}

//tabulation
//TC - O(mxn)
//SC - O(mxn)

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0){
                dp[i][j] = 1;
            }
            else{
                int up = 0;
                int left = 0;

                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

//space optimize
//only using prev row and coloum so can do space optimization

int uniquePaths(int m, int n) {
    vector<int> prev(n,0);
    
    for(int i=0;i<m;i++){
        vector<int> curr(n,0);
        for(int j=0;j<n;j++){
            if(i == 0 && j == 0){
                curr[j] = 1;
            }
            else{
                int up = 0;
                int left = 0;

                if(i>0){
                    up = prev[j];
                }
                if(j>0){
                    left = curr[j-1];
                }
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

//https://www.youtube.com/watch?v=t_f0nwwdg5o
//combinatrix used

int countPaths(int i,int j,int m,int n){
    if(i == m-1 && j == n-1) return 1;
    if(i>=m || j>=n) return 0;
    else return countPaths(i+1,j,m,n) + countPaths(i,j+1,m,n);//bottom or right
}



int countPaths(int i,int j,int m,int n,vector<vector<int>>& dp){
    if(i == m-1 && j == n-1) return 1;
    if(i>=m || j>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    else return dp[i][j] = countPaths(i+1,j,m,n,dp) + countPaths(i,j+1,m,n,dp);//bottom or right
    
}


//combinatrix used
int uniquePaths(int m, int n) {
    int N = m+n-2;
    int r = m-1;
    double res = 1;

    for(int i=1;i<=r;i++){
        res = res*(N-r+i)/i; //int 10C3 = 10*9*8/3*2*1
    }
}
