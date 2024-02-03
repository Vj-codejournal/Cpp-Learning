//https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
//here graph is from 0
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(int src,vector<int> adj[],int vis[]){
        vis[src] = 1;
        queue<pair<int,int>> q;
        q.push({src,-1});

        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto adjacentNode : adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode,node});

                }
                else if(parent != adjacentNode){//when it is visited but it is not the parent node of the current node  
                    return true;
                }
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
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;

    }
};

//TC - O(V+2E)
//worst case have to visit the complete adj list so summation of all the degrees for BFS ignore V loop for components as not necessary call that for each node as 1 root will visit  all its components so ignore it

//SC-O(N)