#include<bits/stdc++.h>

using namespace std;
class DisJointSet{
    vector<int> rank,parent,size;
    public:
    DisJointSet(int n){
        rank.resize(n+1,0);//as 1 based indexing graph
        size.resize(n+1);//as 1 based indexing graph
        parent.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
        
    }
    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }//and assign all in between to ultimate parent by backtracking
        return parent[node] = findUpar(parent[node]);//store this value as in future if some one asl again so path compression now O(1)    
    }

    void unionByRank(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v){
            return;
        }//as belong to same component so no union
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }//smaller attach to larger no change in rank as it already has more height nothing happen if a small set attach to attached
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_u == ulp_v){
            return;
        }

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
       
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

    }

    
};
class Solution
{
    public:
    int spanningTree(int V,vector<vector<int>> adj[]){//adj list is in form index is the node at each index stored in form adjnode,weight
        vector<pair<int,pair<int,int>>> edges;//as bidirectional
        //O(V+E) V is vertices 
        for(int i = 0;i<V;i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt,{node,adjNode}});//no need to add the opposite edge of it discard automatically in disjoint set

            }
        }
        DisJointSet ds(V);

        sort(edges.begin(),edges.end());//O(MlogM)  M is edges
        int mstWt = 0;
        //M x 4 x alpha * 2
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if(ds.findUpar(u) != ds.findUpar(v)){//disjoint sets so union
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstWt;
    }
};
int main(){
    return 0;
}
//SC - O(M) for parent and size vector