#include<bits/stdc++.h>
using namespace std;


bool f(int ind,int target,vector<int>& arr){
    if(target == 0) return true;//if achive target anytime
    if(ind == 0) return (arr[0] == target);//if at last index and target is same as last element for it to return true

    bool notTake = f(ind-1,target,arr);//have two options take the element or not and then gp for smaller subproblem accordingly
    bool take =  false;
    if(arr[ind] <= target){
        take = f(ind-1,target-arr[ind],arr);
    }

    return notTake || take;//from either if we get true our work is done
}



bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();

        return f(n-1,sum,arr);
    }

//TC O(2^n) SC O(n)

//memoization
bool f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target == 0) return true;//if achive target anytime
    if(ind == 0) return (arr[0] == target);//if at last index and target is same as last element for it to return true
    if(dp[ind][target] != -1)return dp[ind][target];//need -1 for unvisited state so can take bool dp array here
    bool notTake = f(ind-1,target,arr,dp);//have two options take the element or not and then gp for smaller subproblem accordingly
    bool take =  false;
    if(arr[ind] <= target){
        take = f(ind-1,target-arr[ind],arr,dp);
    }

    return dp[ind][target] = notTake || take;//from either if we get true our work is done
}



bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }

//TC O(n*target) SC O(n*target) + O(N) for recursion stack


//tabulation
bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));//now need no -1 can take bool dp array
        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }//for any ind if target is 0 then true
        if(arr[0] <= sum)dp[0][arr[0]] = true;//if only one element and target is same as that element then true
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=sum;target++){
                bool notTake = dp[ind-1][target];
                bool take = false;
                if(arr[ind] <= target){
                    take = dp[ind-1][target-arr[ind]];
                }
                dp[ind][target] = notTake || take;
            }
        }

        return dp[n-1][sum];
    }


//space optimized 
//for(int i = 0;i<n;i++){
        //     dp[i][0] = true;
        // }
        //we did  this before now when declare each curr row have to keep 1st coloum as true


bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<bool> prev(sum+1,0),curr(sum+1,0);
        prev[0] = curr[0] = true;
        if(arr[0] <= sum)prev[arr[0]] = true;//if only one element and target is same as that element then true
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<=sum;target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[ind] <= target){
                    take = prev[target-arr[ind]];
                }
                curr[target] = notTake || take;
            }
            prev = curr;
        }

        return prev[sum];
}