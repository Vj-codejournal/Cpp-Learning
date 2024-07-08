//as max greedy think
// 10 50 1  day 0
//5 100 11  day 1
//acc to greedy 50 +11 but actual max 10 + 100 so greedy fails
//think try all possible ways so recurssion
//cant do same thing as last day so have to remember that also


#include <bits/stdc++.h>

using namespace std;
int find(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(day == 0){//for last day(base case) go to all other tasks accept one done on last day
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
    return dp[day][last] = maxi;//returns last wale day tak best achive aase aay jayga
}
int ninjaTraining(int n,vector<vector<int>> &points){   
    vector<vector<int>> dp(n,vector<int> (4,-1));
    return find(n-1,3,points,dp);
}
int main(){
    
    return 0;
}

//tabulation
//start at base case write for all [0][0], [0][1] , [0][2] , [0][3] do all






int ninjaTraining(int n,vector<vector<int>> &points){   
    vector<vector<int>> dp(n,vector<int> (4,0));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0],points[0][1],points[0][2]);

    for(int day = 1;day<n;day++){
        for(int last = 0;last<4;last++){
            dp[day][last] = 0;
            int maxi = 0;
            for(int task = 0;task<3;task++){
                if(task!=last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int main(){
    
    return 0;
}


//space optimize
//no need of nx4 dp array new a single array of 4 keep using it at each step for storing prev one 
//like prev curr in 1D here complete array

int ninjaTraining(int n,vector<vector<int>> &points){   
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],points[0][1],points[0][2]);

    for(int day = 1;day<n;day++){
        vector<int> temp(4,0);
        for(int last = 0;last<4;last++){
            temp[last] = 0;
            
            for(int task = 0;task<3;task++){
                if(task!=last){
                   temp[last] = max(temp[last],points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int main(){
    
    return 0;
}
