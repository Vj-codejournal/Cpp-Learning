//MEMOISATION method

#include <bits/stdc++.h>

using namespace std;
int fac(int n,vector<int> &dp){
    if(n<= 1) return 1;

    if(dp[n] != -1) return dp[n];

    return dp[n] = fac(n-1,dp)+fac(n-2,dp);
}
int main(){
    int n;
    cin>>n;
    // int dp[n+1];
    // memset(dp,-1,sizeof dp);//gloabal variable?
    vector<int> dp(n+1,-1);
    return 0;
}//TC - O(N) can see from recursion tree as we use memorized values that take O(1) so to go in stack O(N) left skew only come
//SC - O(N) + O(N) for arrayand recursion call stack
//what is memset

//TABULATION method with space optimization

#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int prev2 = 0;
    int prev = 1;
    
    for(int i = 2;i<=n;i++){
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }

    cout<<prev;
    return 0;
}



