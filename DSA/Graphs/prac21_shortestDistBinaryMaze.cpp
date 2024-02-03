//https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));

        dist[source.first][source.second] = 0;

        queue<pair<int,pair<int,int>>> q;
        //{dist,{row,col}}

        //insert source in q then remove and go in all dirn according to it
        q.push({0,{source.first,source.second}});
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};//to go in all 4 dirn
        if(source.first==destination.first && source.second==destination.second) 
        return 0; 
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0;i<4;i++){
                int newr = r+delRow[i];
                int newc = c+ delCol[i];

                if(newr >= 0 && newr<n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dist[newr][newc] > dis +1){
                    dist[newr][newc] = dis + 1;
                    if(newr == destination.first && newc == destination.second) return dis+1;
                    q.push({dis+1,{newr,newc}});
                }
            }


        }
        return -1;
    }
};

int main(){
    
    return 0;
}

//take another matrix make src 0 and other 1e9 then do shortest dist by 4 moves left right up down
//here priority queue not needed as all dist are 1 so all adj nodes inserted in priority queue will have same dist can use queuev 

