#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});

        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//for min heap
        vector<int> dist(n+1,1e9);
        vector<int> parent(n+1);
        for(int i = 0;i<=n;i++)parent[i] = i;

        dist[1] = 0;
        pq.push({0,1});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                    parent[adjNode] = node;
                }
            }

        }
        if(dist[n] == 1e9) return {-1};
        vector<int>path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
        
    }
};
int main(){
    
    return 0;
}

//tell the path
//remember the path you are coming from make a parent array


//TC ElogV + V as V for backtrack worst case and E is V^2 so ignore V