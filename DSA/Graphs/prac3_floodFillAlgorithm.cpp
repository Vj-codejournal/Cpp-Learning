#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    void bfs(vector<vector<int>>& image, int sr, int sc, int newColor,int chosen,vector<vector<int>> &vis){
        int n = image.size();
        int m = image[0].size();
        vis[sr][sc] = 1;
        image[sr][sc] = newColor;
        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            int sr = q.front().first;
            int sc = q.front().second;

            q.pop();
            for(int row = sr - 1;row <= sr+1;row++){
                if(row>=0 && row<n && image[row][sc] == chosen && !vis[row][sc]){
                    image[row][sc] = newColor;
                    vis[row][sc] = 1;
                    q.push({row,sc});
                }
            }
            for(int col = sc - 1;col <= sc+1;col++){
                if(col>=0 && col <m && image[sr][col] == chosen && !vis[sr][col]){
                    image[sr][col] = newColor;
                    vis[sr][col] = 1;
                    q.push({sr,col});
                }
            }

        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int chosen = image[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));

        bfs(image,sr,sc,newColor,chosen,vis);

        return image;
    }
};

//dfs

#include<bits/stdc++.h>
using namespace std;


class Solution2{
public:

    void dfs(int row,int col,vector<vector<int>> &ans,vector<vector<int>> &image,int newColor,int delRow[],int delCol[],int iniColor){
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0;i<4;i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor){//last condtion for checking visited
                dfs(nrow,ncol,ans,image,newColor,delRow,delCol,iniColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;

        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};

        dfs(sr,sc,ans,image,newColor,delRow,delCol,iniColor);

    }
};


/*
                row-1,col
row,col-1        row,col    row,col+1
                row+1,col

make all four pairs in delROW and delCol accordingly
*/

//TC O(n x m)

//for worst case all have same as inicolour nxm node = let X nodes
//for each of X a for loop of 4 times called so X x 4 is TC apporx X which is n x m

//SC O(N*M) + O(N*M) as max recursive stack can have all nodes and ans matrix also 

