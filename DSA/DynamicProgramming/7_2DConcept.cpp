//as max greedy think
// 10 50 1  day 0
//5 100 11  day 1
//acc to greedy 50 +11 but actual max 10 + 100 so greedy fails
//think try all possible ways so recurssion
//cant do same thing as last day so have to remember that also


#include <bits/stdc++.h>

using namespace std;
int find(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int task = 0;task<3;task++){
            if(task != last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1)return dp[day][last];
    int maxi = 0;
    for(int task = 0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + find(day-1,task,points,dp);
            maxi = max(maxi,point);

        }

    }
    return maxi;
}
int ninjaTraining(int n,vector<vector<int>> &points){   
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return find(n-1,3,points,dp);
}
int main(){
    
    return 0;
}