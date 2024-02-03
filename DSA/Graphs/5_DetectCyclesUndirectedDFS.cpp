//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//here graph is from 0
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool dfs(int node,int parent,vector<int> adj[],int vis[]){
        vis[node] = 1;
        for(auto adjacentNode: adj[node]){
            if(!vis[adjacentNode]){//if not visited
                if(dfs(adjacentNode,node,adj,vis) == true) return true;
            }
            else if(adjacentNode != parent){//if it is visited but it is not parent then it is a cycle
                return true;
            }
        }
        return false;
    }
  public:
    
    bool isCycle(int V, vector<int> adj[]) {
        //for connected components can be present
        int vis[V] = {0};

        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,adj,vis)) return true;
            }
        }
        return false;

    }
};

//SC O(V) +O(V) //worst case recursion stack has all V

//TC O(V+2E)     + O (V) -> is for forloop 