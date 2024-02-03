//Depth First Search Traversal Techinque

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void DFS(int node,vector<int> adj[], int vis[] , vector<int> &ls){
        vis[node] = 1;
        ls.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                DFS(it,adj,vis,ls);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        DFS(start,adj,vis,ls);
        return ls;
    }
};

//SC - O(N) + O(N) + O(N) for ls ,vis and max recursion stack can be for skew that is also n

//TC -  O(N) + O(2E) in directed 2E replace with actual number of edges