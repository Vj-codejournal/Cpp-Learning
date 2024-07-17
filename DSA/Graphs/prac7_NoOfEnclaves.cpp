//https://practice.geeksforgeeks.org/problems/number-of-enclaves/1


#include <bits/stdc++.h>
using namespace std;



class Solution {
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid){
        //cout<<"called"<<row<<col<<endl;
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        //in 4 dirn up down left right
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        for(int i = 0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,vis,grid);        
            }
        }

    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        //same as prac6_ReplaceOwithX those 1 which are not connected to 1 on boundary will never be able to walk of from them so start at boundary find 1s which are connected to 1s on boundary and apply dfs and mark them as visited then finally those who are left will be the answer
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j = 0;j<m;j++){
            //firstrow
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0,j,vis,grid);
            }
            //last row
            if(!vis[n-1][j] && grid[n-1][j] == 1){
                dfs(n-1,j,vis,grid);
            }
        }

        for(int i = 0;i<n;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,vis,grid);
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                    
                }
            }
        }
        return cnt;
    }
    
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}