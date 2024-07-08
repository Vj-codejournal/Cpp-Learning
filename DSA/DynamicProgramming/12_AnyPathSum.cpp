//start can be anything from first row and end can be anything from last row both variable
//can move diagonally down left,down right and down
//get max

//can end at any coloum in last row so m options so call recursively for all m options(in this there will be overlapping subprob) and base case any one in first row
//now go up

//normal recursion TC 3^n


//memoization
#include<bits/stdc++.h>
using namespace std;
int f(int i,int j,vector<vector<int>> &matrix, vector<vector<int>>& dp){
        int m = matrix[0].size();
        if(j<0 || j>=m)return 1e9;
        if(i ==0) return matrix[0][j];
        if(dp[i][j] != -1)return dp[i][j];

        int sup = matrix[i][j] + f(i-1,j,matrix,dp);
        int lup = matrix[i][j] + f(i-1,j-1,matrix,dp);
        int rup = matrix[i][j] + f(i-1,j+1,matrix,dp);

        return dp[i][j] = min(sup,min(lup,rup));

    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int minans = 1e9;
        for(int i = 0;i<m;i++){
            int temp = f(n-1,i,matrix,dp);
            minans = min(temp,minans);
        }

        return minans;
    }


//tabulation

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){//base case for tabulation start at first row
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int lup = 1e9;
                int sup = matrix[i][j] + dp[i-1][j];
                if(j-1>=0) lup = matrix[i][j] + (dp[i-1][j-1]);
                
                int rup = matrix[i][j] + (j+1<m?dp[i-1][j+1]:1e9);
                dp[i][j] = min(sup,min(lup,rup));
            }
        }
        int minans = 1e9;
        for(int i = 0;i<m;i++){
            minans = min(minans,dp[n-1][i]);
        }
        return minans;
    }


//space optimization

int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> prev(m,0) , curr(m,0);
        for(int i=0;i<m;i++){//base case for tabulation start at first row
            prev[i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int lup = 1e9;
                int sup = matrix[i][j] + prev[j];
                if(j-1>=0) lup = matrix[i][j] + (prev[j-1]);
                
                int rup = matrix[i][j] + (j+1<m?prev[j+1]:1e9);
                curr[j] = min(sup,min(lup,rup));
            }
            prev = curr;
        }
        int minans = 1e9;
        for(int i = 0;i<m;i++){
            minans = min(minans,prev[i]);
        }
        return minans;
    }