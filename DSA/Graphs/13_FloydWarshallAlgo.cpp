#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
    void shortest_distance(vector<vector<int>>&matrix){
        int n = matrix.size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == -1){
                    matrix[i][j] = 1e9;
                }
                if(i == j){
                    matrix[i][j] = 0;
                }
            }
        }

        for(int k = 0;k<n;k++){//as have to do via each node
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
        //negative cycle
        for(int i = 0;i<n;i++){
            if(matrix[i][i]<0){
                cout<<"Negative cycle";
                return;
            }
        }

        //as all unreachable nodes are -1
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j] == 1e9){
                    matrix[i][j] = -1;
                }
                
            }
        }
    }
};
//TC - O(N^3)
// SC - O(N^2)
int main(){
    
    return 0;
}

//dijkstra not work on negative cycle but can do dijkstra on every node take v x e x log v if no negative cycle


