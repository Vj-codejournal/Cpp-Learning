//https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1

//as distance level by level so BFS

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

 
class Solution 
{
    
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        //nxm here
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }//initial 1 stored in the queue

                
            }
        }
        //nxmx4 here worst 
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;

            q.pop();
            dist[row][col] = steps;

            for(int i = 0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];

                if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && vis[nrow][ncol] == 0){
                    vis[nrow][ncol] = 1;
                    q.push({{nrow,ncol},steps +1});
                }
                
            }


        }
        return dist;
	}
};

//so total TC = O(nxm) + O(nxmx4) = O(nxm)


//i done by going to nearest from 0 in video he took 1 and do all nearest to it and where 0 convert them
//TLE
// class Solution 
// {
//     void finder(int i1,int j1,vector<vector<int>> &ans,vector<vector<int>> &grid,int delRow[],int delCol[]){
//         int n = grid.size();
//         int m = grid[0].size();
//         queue<pair<int,int>> q;
//         q.push({i1,j1});

//         while(!q.empty()){
//             int tempi = q.front().first;
//             int tempj = q.front().second;

//             q.pop();
//             for(int i = 0;i<4;i++){
//                 int nrow = tempi + delRow[i];
//                 int ncol = tempj + delCol[i];

//                 if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && grid[nrow][ncol] == 0){
//                     q.push({nrow,ncol});
//                 }
//                 else if(nrow>=0 && nrow<n && ncol >= 0 && ncol<m && grid[nrow][ncol] == 1){
//                     int finalvalue = abs(nrow - i1) + abs(ncol - j1);

//                     ans[i1][j1] = finalvalue;
//                     return;
//                 }
//             }
//         }
//     }
//     public:
//     //Function to find distance of nearest 1 in the grid for each cell.
// 	vector<vector<int>>nearest(vector<vector<int>>grid)
// 	{
// 	    int n = grid.size();
//         int m = grid[0].size();
//         vector<vector<int>> ans(n,vector<int>(m,0));
//         int delRow[] = {-1,0,+1,0};
//         int delCol[] = {0,+1,0,-1};
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<m;j++){
//                 if(grid[i][j] == 0){
//                     finder(i,j,ans,grid,delRow,delCol);
//                 }
                
//             }
//         }
//         return ans;
// 	}
// };