#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind,int prev_ind,vector<int> &nums){
        int n = nums.size();

        if(ind == n)return 0;

        int len = 0 + f(ind+1,prev_ind,nums);//not take

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){//if current ind is greater or have no one at prev
            len = max(len , 1+ f(ind+1,ind,nums));
        }

        return len;

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        
        return f(0,-1,nums);
    }
};

//memoization

class Solution {
public:
    int f(int ind,int prev_ind,vector<int> &nums,vector<vector<int>> &dp){
        int n = nums.size();

        if(ind == n)return 0;
        if(dp[ind][prev_ind+1] != -1)return dp[ind][prev_ind+1];
        int len = 0 + f(ind+1,prev_ind,nums,dp);//not take

        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){//if current ind is greater or have no one at prev
            len = max(len , 1+ f(ind+1,ind,nums,dp));
        }

        return dp[ind][prev_ind+1] = len;//as coordinate change so +1

    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,nums,dp);
    }
};


//BInary search
