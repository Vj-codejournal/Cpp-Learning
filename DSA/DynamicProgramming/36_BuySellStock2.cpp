#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int f(int ind,int buy,vector<int> & values,vector<vector<int>> &dp){
        int n = values.size();
        if(ind == n)return 0; //even if at n buy a stock not matter as no profit from that can get
        if(dp[ind][buy] != -1)return dp[ind][buy];
        int profit = 0;

        if(buy){ // as if buy deduct it from profit when we sell in else it will be added to profit
            profit = max(-values[ind] + f(ind+1, 0, values,dp),  0 + f(ind+1,1, values,dp)); //buy current or not //if buy then remove its prices as we are buying it and go to next day with 0 as cant by after that other is not buy on that day so next day and 1 as still can buy
        }
        else{
            profit = max(values[ind] + f(ind+1,1, values,dp) , 0 + f(ind+1,0, values,dp));
        }
        return dp[ind][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};


//tabulation

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        
        dp[n][0] = dp[n][1] = 0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit = max(prices[ind] + dp[ind+1][1], 0 + dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }

        return dp[0][1];        
}




//space optimized
int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2,0) , curr(2,0);
        
        ahead[0] = ahead[1] = 0;
        for(int ind = n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                long profit = 0;
                if(buy){
                    profit = max(-prices[ind] + ahead[0], 0 + ahead[1]);
                }
                else{
                    profit = max(prices[ind] + ahead[1], 0 + ahead[0]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1];        
}

//can do using 4 variables as well see video