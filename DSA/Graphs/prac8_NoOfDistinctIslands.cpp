//https://www.geeksforgeeks.org/problems/number-of-distinct-islands/1

//to get distinct store in set
//store each set of points in list take a base point substract from other points of list gets same list as any other then identical islands


#include <bits/stdc++.h>

using namespace std;
class Solution {

    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid,vector<pair<int,int>> &vec,int n,int m,int row0,int col0){//last two are base coordinates from which we are starting dfs
        
        vis[row][col] = 1;
        vec.push_back({row-row0,col-col0});

        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,-1,0,+1};

        for(int i = 0 ;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow,ncol,vis,grid,vec,n,m,row0,col0);
            }
        }
        
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>> st;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int,int>> vec;
                    dfs(i,j,vis,grid,vec,n,m,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();

    }
};

int main(){
    
    return 0;
}
 
//SC = O(N*M) as if all points visited then this

//TC = N*M*log(N*M) as n*m is set length to store all  for st.insert
//     + N*M*4 for dfs if worst it goes for all elements of matrix(all 1)