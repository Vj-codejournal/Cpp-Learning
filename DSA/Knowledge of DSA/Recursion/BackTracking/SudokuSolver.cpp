#include <bits/stdc++.h>

using namespace std;
class Solution {

    bool isSafe(int row,int col,vector<vector<char>>& board,char val){
        
        for(int i = 0;i<board.size();i++){
            //row check
            if(board[row][i] == val){
                return false;
            }
            //col check
            if(board[i][col]== val){
                return false;
            }

            //3*3 matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int n = board.size();
        
        for(int row = 0;row<n;row++){
            for(int col = 0;col<n;col++){


                if(board[row][col] == '.'){
                    for(char val = '1';val<='9';val++){
                        //char valInChar = val + '0';
                        if(isSafe(row,col,board,val)){
                            board[row][col] = val;
                            if(solve(board)){//recursion  if going forward is possible 
                                return true;
                            }
                            else{
                                board[row][col] = '.';//backtrack
                            }
                        }
                    }
                    return false;//all val 1 to 9  tried but not accepted
                }
                


            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
int main(){
    
    return 0;
}