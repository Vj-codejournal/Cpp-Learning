#include <bits/stdc++.h>

using namespace std;
class Solution{
    bool isSafe(int x,int y,int n,vector<vector<int>> &visited,vector<vector<int>> &m){
        if((x>=0 && x<n) && (y>=0 && y<n) && m[x][y] == 1 && visited[x][y] == 0){
            return true;
        }
        else
        return false;
    }
    void solve(vector<vector<int>> &m,int n,vector<string> &ans,int x,int y,vector<vector<int>> &visited,string path){
        //base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;
        //D,L,R,U
        //down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('D');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();//backtrack path string ko wapis khali bhi karna padega and explore other route also from each position
        }
        //left
        newx = x;
        newy = y-1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('L');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        //right
        newx = x;
        newy = y+1;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('R');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        //up
        newx = x-1;
        newy = y;
        if(isSafe(newx,newy,n,visited,m)){
            path.push_back('U');
            solve(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        //backtracking
        visited[x][y] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0) return ans; //as no start
        int srcx = 0;
        int srcy = 0;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = "";

        solve(m,n,ans,srcx,srcy,visited,path);
        sort(ans.begin(),ans.end());//lexicographically sort

        return ans;
    }
};

int main(){
    
    return 0;
}

/*
up (x-1,y)
down (x+1,y)
left (x,y-1)
right (x,y+1)
*/