#include <bits/stdc++.h> 
using namespace std;


int f(int ind,int W,vector<int>& weight,vector<int>& value,vector<vector<int>>& dp){
    if(ind == 0){
        if(weight[ind] <= W)return value[0];
        else return 0;
    }
    if(dp[ind][W] != -1)return dp[ind][W];
    int notTake = 0 + f(ind-1,W,weight,value,dp);
    int take = INT_MIN;
    if(weight[ind] <= W){
        take = value[ind] + f(ind-1,W-weight[ind],weight,value,dp);
    }

    return dp[ind][W] = max(take,notTake);

}
    
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}


///tabulation

    
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
    vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	
    for(int w = weight[0];w<=maxWeight;w++){
        dp[0][w] = value[0];
    }

    for(int ind = 1;ind<n;ind++){
        for(int w = 0;w<=maxWeight;w++){
            int notTake = 0 + dp[ind-1][w];
            int take = INT_MIN;
            if(weight[ind] <= w){
                take = value[ind] + dp[ind-1][w -weight[ind]];
            }

            dp[ind][w] = max(take,notTake);
        }
    }
    return dp[n-1][maxWeight];
}

//space optimize 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
    vector<int> prev(maxWeight+1,0),curr(maxWeight+1,0);
	
    for(int w = weight[0];w<=maxWeight;w++){
        prev[w] = value[0];
    }

    for(int ind = 1;ind<n;ind++){
        for(int w = 0;w<=maxWeight;w++){
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if(weight[ind] <= w){
                take = value[ind] + prev[w -weight[ind]];
            }

            curr[w] = max(take,notTake);
        }
        prev= curr;
    }
    return curr[maxWeight];
}

//optimize in single array

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
    vector<int> prev(maxWeight+1,0);
	
    for(int w = weight[0];w<=maxWeight;w++){
        prev[w] = value[0];
    }

    for(int ind = 1;ind<n;ind++){
        for(int w = maxWeight;w >=0 ;w--){
            int notTake = 0 + prev[w];
            int take = INT_MIN;
            if(weight[ind] <= w){
                take = value[ind] + prev[w -weight[ind]];
            }

            prev[w] = max(take,notTake);
        }
        
    }
    return prev[maxWeight];
}