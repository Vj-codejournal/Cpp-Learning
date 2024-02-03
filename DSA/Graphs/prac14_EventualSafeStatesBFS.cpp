//Topological sort 

//https://leetcode.com/problems/find-eventual-safe-states/description/

//cycle detection in directed graph
#include <bits/stdc++.h>

using namespace std;
class Solution {
   
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>adjRev[V];//extra space then general topology
        int indegree[V] ;
        for(int i = 0;i<V;i++){
            indegree[i] = 0;
        }
        for(int  i = 0;i<V;i++){
            //i -> it
            //make it -> i
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;
        for(int i =0 ;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }

        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }



        sort(safeNodes.begin(),safeNodes.end());//nlogn TC worst case
        return safeNodes;
    }
};
int main(){
    
    return 0;
}