//https://practice.geeksforgeeks.org/problems/number-of-provinces/1
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
       void DFS(int node,vector<int> adjlis[], int vis[] ){
        vis[node] = 1;
        

        for(auto it : adjlis[node]){
            if(!vis[it]){
                DFS(it,adjlis,vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {   vector<int> adjlis[V];//0 will store for 1
        //convert matrix to adjacency list
        for(int i = 0;i<V;i++){
            for(int j = 0;j<V;j++){
                if(adj[i][j] == 1 && i != j){
                    adjlis[i].push_back(j);
                    adjlis[j].push_back(i);

                }
            }
        }
        int provinces = 0;

        int vis[V] = {0};
        //check for all components ******this method use
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                
                DFS(i,adjlis,vis);
                provinces++;
            }
        }

        return provinces;
    } 
};
int main()
{

    return 0;
}
//TC - O(N) + O(V+2E) not O(N) * O(V+2E) as dfs called N time only one time for each node so O(V+2E) for that only

//SC- O(N) + O(N) visited array and dfs recursion stack worst skew

// TLE
/*
      void DFS(int i ,vector<vector<int>> adj, int vis[],int V ){
        vis[i] = 1;


        for(int j = 0;j<V;j++){
            if(adj[i-1][j] == 1 && !vis[j+1] ){
                DFS(j+1,adj,vis,V);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        int provinces = 0;

        int vis[V+1] = {0};

        for(int i = 1;i<=V ;i++){
            if(!vis[i]){
                DFS(i,adj,vis,V);

                provinces++;
            }
        }

       return provinces;
     }
*/