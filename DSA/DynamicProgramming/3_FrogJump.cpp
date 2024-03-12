#include <bits/stdc++.h>

using namespace std;
int find(int ind, vector<int> &heights,vector<int> &dp){
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }

    int left = find(ind - 1,heights,dp) + abs(heights[ind] - heights[ind - 1]);;
    int right = INT_MAX;
    if(ind>1)right = find(ind -2,heights,dp) + abs(heights[ind] - heights[ind - 2]);

    return dp[ind] = min(left,right);

}

int frogJump(int n, vector<int> &heights){
    vector<int> dp (n + 1, -1);
    return find(n-1,heights,dp);
}
int main(){
    
    return 0;
}

 

//tabulation
int frogJump(int n, vector<int> &heights){
    vector<int> dp (n + 1, -1);
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        int fs = dp[i-1] + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if(i>1)
        ss = dp[i-2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(fs,ss);
    }
    return dp[n-1];//n-1 stores the minimum jump path
}


//tabulation space optimization
int frogJump(int n, vector<int> &heights){
    
    int prev = 0;
    int prev2 = 0;
    for(int i = 0;i<n;i++){
        int fs = prev + abs(heights[i] - heights[i - 1]);
        int ss = INT_MAX;
        if(i>1)
        ss = prev2 + abs(heights[i] - heights[i - 2]);

        int curr = min(fs,ss);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


//IF jump to k steps
//no space optimization here

//memoization  for each recursion call loop run k time and recursion call n times
//TC O(N*K) SC - O(N) + O(N)

int find(int ind, vector<int> &heights,vector<int> &dp,int k){
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
        int mmsteps = INT_MAX;
    for(int j = 1;j<k;j++){
        if(ind - j>= 0){
            int jump = find(ind - j,heights,dp,k) + abs(heights[ind] - heights[ind - j]);
            mmsteps = min(jump,mmsteps);
        }

    }

    return dp[ind] = mmsteps;
    

}

int frogJump(int n, vector<int> &heights,int k){
    vector<int> dp (n + 1, -1);
    return find(n-1,heights,dp,k);
}


//tabulation

int frogJump(int n, vector<int> &heights,int k){
    vector<int> dp (n + 1, -1);
    dp[0] = 0;
    for(int i = 0;i<n;i++){
        int minsteps = INT_MAX;
        for(int j= 1;j<k;j++){
            if(i-j>= 0){
                int jump = dp[i-j] + abs(heights[i] - heights[i - j]);
                minsteps = min(minsteps,jump);   
            }
        }
        dp[i] = minsteps;
        
    }
    return dp[n-1];//n-1 stores the minimum jump path
}

//TC O(N*K) SC - O(N)

//can space optimize to O(k)
// for  2 needed prev and prev2 so for k need prev to prevk steps 
//carry a list at each step we move forward remove first element and add last element