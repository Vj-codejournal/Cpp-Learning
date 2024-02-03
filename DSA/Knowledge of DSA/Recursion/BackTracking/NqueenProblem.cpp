#include <bits/stdc++.h>

using namespace std;
class Solution {

    void addSolution(vector<vector<string>> & ans,vector<vector<string>> & board,int n){
        vector<string> temp;
        for(int i = 0;i<n;i++){
            string s = "";
            for(int j = 0;j<n;j++){
                s += board[i][j];
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
        
    }
    bool isSafe(int row,int col,vector<vector<string>> & board,int n){
        //safe means not in same row column and diagonal of prev queen or current queen ke liye sab dirn check kar lo uske path mai koi queen aay gayi to reject

        int x = row;
        int y = col;

        //check for same row only to left as right is not filled
        while(y>=0){//O(n) here use mapping when ever place Q map it with index col so O(1) map <col,true>
            if(board[x][y] == "Q"){
                return false;
            }
            y--;
        }

        //each colum only one Q place no need to check

        //check diagnol all four dirn
        x = row;
        y = col;

        while(x>=0 && y >= 0){//upper left
            if(board[x][y] == "Q"){//for diagnol mapping is diffrent see map<n-1 + col - row,true> by this upper diagnols will gave same value 
                return false;
            }
            x--;
            y--;
        }

        x = row;
        y = col;

        while(x<n && y >= 0){//lower left
            if(board[x][y] == "Q"){//for diagnol mapping is diffrent see sum of row and col is same for this so map<row+col,true>
                return false;
            }
            x++;
            y--;
        }
        
        //no need to check right side as not filled yet

        return true;
    }
    
    void solve(int col,vector<vector<string>> & ans,vector<vector<string>> & board,int n){
        if(col == n){//if all column aare filled with 1 queen in each and still safe then save
            addSolution(ans,board,n);
            return; 
        }

        //for 1 colum have to place queen in each row one by one for all cases
        for(int row = 0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = "Q";
                solve(col+1,ans,board,n);
                //backtrack
                board[row][col] = ".";
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> board(n,vector<string>(n,"."));

        vector<vector<string>> ans;
        solve(0,ans,board,n);

        return ans;
    }
};
int main(){
    
    return 0;
}