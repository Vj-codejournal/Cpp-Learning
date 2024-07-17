#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int f(int ind,int buy,int cap,vector<int> & values,vector<vector<vector<int>>> &dp){
        int n = values.size();
        if(ind == n|| cap ==0)return 0; //even if at n buy a stock not matter as no profit from that can get
        if(dp[ind][buy][cap] != -1)return dp[ind][buy][cap];
        int profit = 0;

        if(buy){ // as if buy deduct it from profit when we sell in else it will be added to profit
            profit = max(-values[ind] + f(ind+1, 0,cap, values,dp),  0 + f(ind+1,1,cap, values,dp)); //buy current or not //if buy then remove its prices as we are buying it and go to next day with 0 as cant by after that other is not buy on that day so next day and 1 as still can buy
        }
        else{
            profit = max(values[ind] + f(ind+1,1,cap-1, values,dp) , 0 + f(ind+1,0,cap, values,dp));
        }
        return dp[ind][buy][cap] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};


//tabulation

/*
base case 
cap = 0 ind and buy anything
for(int  0 to n-1)
    for(buy 0 to 1)
        dp[ind][buy][0] = 0

ind == n

for(buy 0 to 1)
    for(cap 0 to 2)
        dp[n][buy][cap] = 0



i from n-1 to 0
buy from 0 to 1
cap from 0 to 2

*/

int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));

        for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {
                if (buy == 1) { // We can buy the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][1][cap], -prices[ind] + dp[ind + 1][0][cap]);
                }

                else { // We can sell the stock
                    dp[ind][buy][cap] = max(0 + dp[ind + 1][0][cap], prices[ind] + dp[ind + 1][1][cap - 1]);
                }
            }
        }
    }

    // The result is stored in dp[0][1][2] which represents maximum profit after the final transaction.
    return dp[0][1][2];

}

//can do space optimize after and curr vector


//transaction method there will be 4 transaction only B S B S so when ever buy or sell reduce a transaction so 2D dp will be enough