

#include <bits/stdc++.h>


using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> effort(n,vector<int>(m,1e9));

        effort[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //{diff,{row,col}}
        pq.push({effort[0][0],{0,0}});
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        while(!pq.empty()){//use  pq as minimal effort
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n-1 && c == m-1)return diff;//here and not in loop as can find more shorter differnce while the loop is going even before reaching end
            for(int i = 0;i<4;i++){
                int newr = r+delRow[i];
                int newc = c+ delCol[i];

                if(newr >= 0 && newr<n && newc >= 0 && newc < m){
                    //effort[newr][newc] = max(effort[r][c],heights[newr][newc] - heights [r][c]);// difference at this step is  heights[newr][newc] - heights [r][c] if it is greater than previous difference till not then it will be forwarded in pq as need max difference in effort //always keep storing the effort only each time
                    int newEffort = max(abs(heights[newr][newc] - heights[r][c]),diff);
                    if(newEffort < effort[newr][newc]){
                        effort[newr][newc] = newEffort;
                    pq.push({effort[newr][newc],{newr,newc}});
                    }

                }
            }
        }
        return 0;
    }
};
int main(){
    
    return 0;
}

//Effort max of all difference in the path 
