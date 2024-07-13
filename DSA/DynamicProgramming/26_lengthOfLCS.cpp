//assume we get dp[][] given 

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    int n,m;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int len = dp[n][m];
    string ans = "";
    for(int i = 0;i<len;i++){
        ans += '$';
    }

    int index = len-1;
    int i = n,j = m;
    while(i>0 && j>0){
        if(s[i-1] == t[j-1]){
            ans[index] = s[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }

    }

    cout<<ans;
}

//O(M+N) worst all row and coloum visit
