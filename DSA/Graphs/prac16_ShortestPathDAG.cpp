//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

#include <bits/stdc++.h>

using namespace std;
class Solution {
    void topoSort(int node,vector<pair<int,int>> adj[],int vis[],stack<int> &st){
        vis[node] = 1;
        for(auto it:adj[node]){
            int v = it.first;
            if(!vis[v]){
                topoSort(v,adj,vis,st);
            }
        }
        st.push(node); 
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){//given no of nodes = n , no of edges = m and edge weight u,v,weight form 
        //make the adj list 
        vector<pair<int,int>> adj[N];
        for(int i = 0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
            //find topo sort
            int vis[N] = {0};
            stack<int> st;
            for(int i = 0;i<N;i++){
                if(!vis[i]){
                    topoSort(i,adj,vis,st);
                }
            }

            //do the distancing
            vector<int>dist(N,1e9);
            //for(int i = 0;i<N;i++) dist[i] = INT_MAX;

            dist[0] = 0; //as src is considered 0
            while(!st.empty()){
                int node = st.top();
                st.pop();

                for(auto it:adj[node]){
                    int v = it.first;
                    int wt = it.second;
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
            //if after complete still any element int_max that means no reachable from source
            //make it -1
            for(int i = 0;i<N;i++){
                if(dist[i] == 1e9){
                    dist[i] = -1;
                }
            }

        return dist;
        
    }
};

int main(){
    
    return 0;
}

//TC - O(N+M) + O(N+M) //as dfs and while we go through stack it goes through adj list which is adj list



  