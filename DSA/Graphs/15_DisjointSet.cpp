#include <bits/stdc++.h>

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
int main(){
    DisJointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);

    if(ds.findUpar(3) == ds.findUpar(7)){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    ds.unionByRank(3,7);
    return 0;
} 