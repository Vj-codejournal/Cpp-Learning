//Shortest path in Undirected Graph having unit distance
//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(int i = 0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dist(N,1e9); 
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();

            for(auto it : adj[node]){
                if(dis+1 < dist[it]){
                    dist[it] = dis+1;
                    q.push({it,dis+1});
                }
            }
        }

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

//TC same as dfs undirected O(V+2E)
