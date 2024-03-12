#include<bits/stdc++.h>

using namespace std;

class Solution
{
    public:
    int spanningTree(int V,vector<vector<int>> adj[]){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> vis(V,0);
        //need MST so store the parent
        pq.push({0,{0,-1}});//wt,node,parent
        int sum = 0;
        vector<pair<int,int>> MST;
        //E all edges go through worst
        while(!pq.empty()){
            auto it = pq.top();//log E for pq to  maintain min heap if 0 connect to all all come in pq so E
            pq.pop();
            pair<int,int> p = it.second;
            int node = p.first;
            int wt = it.first;

            if(vis[node])continue;//already part of mst not go agan or form loop
            sum += wt;//as initial wt already 0 not matter

            if(p.second != -1){//as initial node parent -1 cant include that
                MST.push_back(p);

            }
            //check adj nodes
            //worst E logE move through all edge an pq.push min heap logE
            for(auto it2:adj[node]){
                int adjNode = it2[0];
                int edW = it2[1];
                if(!vis[adjNode]){//adjcent node should not be visited then only add to queue
                    pq.push({edW,{adjNode,node}});
                }
            }
            
        }
        //O(ElogE + ElogE) while and pq.top run together and for is different
        return sum;
    }
};