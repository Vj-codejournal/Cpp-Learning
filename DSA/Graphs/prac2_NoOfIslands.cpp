//https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

//get 1 starting node can traverse rest connected

#include <iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
  public:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse 8 neighbours all have row +1 or -1 and col +1 or -1

            for(int delrow = -1;delrow<=1; delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int nrow = row + delrow;
                    int ncol = col + delcol;
                    if(nrow>= 0 &&nrow<n && ncol>=0 &&ncol<m && grid[nrow][ncol] == '1'&& !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }

    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row = 0;row<n;row++){
            for(int col = 0;col<m;col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};
int main(){
    
    return 0;
}

//make a vis array of nXm to store and do BFS but a change here go in all 8 dirn around a node to check for neighbour and store in queue 

//SC O(N^2)
//TC O(N^2) + O(N^2) * 9
//for nxn matrix loop then if all 1 bfs for nxn time and each time its surrounding 8 are checked



/*
0 1 1 0 
0 1 1 0 
0 0 1 0 
0 0 0 0 
1 1 0 1
*/