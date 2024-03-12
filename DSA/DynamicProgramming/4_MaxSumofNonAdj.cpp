//for each element have to see all pairs execpt one next to it so recursion
//no two picked elements should be adjacent to each other


//start from a number either we can pick it or not pick it 2 options if pick cant pick its adj if not pick then pick its adjacent
//start from n and go to 0 pick and not pick each for all options
//TC - O(2^n) as all possible cases



#include <bits/stdc++.h>

using namespace std;
int find(int ind,vector<int> &nums,vector<int> &dp){
    if(ind == 0)return nums[ind];
    if(ind<0) return 0;

    if(dp[ind] != -1)return dp[ind];
    int pick = nums[ind] + find(ind-2,nums,dp);
    int notPick = find(ind-1,nums,dp);
    return dp[ind] =  max(pick,notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);

    return find(n-1,nums,dp);
}
int main(){
    
    return 0;
}
//TC - O(N)

//Tabulation
//base to up
/*
dp[0] = a[0];
int neg = 0;

for(int i = 0;i<n;i++){
    take = a[ind]; if(i>1) take += dp[i-2];
    notTake = 0 + dp[i-1];
    dp[i] = max(take,notTake);
}
*/

/*
need i-1 and i-2 only so space optimize
prev = a[0];
int prev2 = 0;

for(int i = 0;i<n;i++){
    take = a[ind]; if(i>1) take += prev2;
    notTake = 0 + prev;
    curr = max(take,notTake);

    prev2 = prev;
    prev = curr;
}
return prev;

TC O(N)
SC O(1)
*/