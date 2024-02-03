//https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

//if any O at boundary then all O connected to it cannot be covered from all sides so start from boundry find O apply DFS


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &mat){
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        //in 4 dirn up down left right
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        for(int i = 0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                dfs(nrow,ncol,vis,mat);        
            }
        }

    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j = 0;j<m;j++){
            //firstrow
            if(!vis[0][j] && mat[0][j] == 'O'){
                dfs(0,j,vis,mat);
            }
            //last row
            if(!vis[n-1][j] && mat[n-1][j] == 'O'){
                dfs(n-1,j,vis,mat);
            }
        }

        for(int i = 0;i<n;i++){
            if(!vis[i][0] && mat[i][0] == 'O'){
                dfs(i,0,vis,mat);
            }
            if(!vis[i][m-1] && mat[i][m-1] == 'O'){
                dfs(i,m-1,vis,mat);
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
}; 