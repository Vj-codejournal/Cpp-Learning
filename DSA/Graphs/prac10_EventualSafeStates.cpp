//https://leetcode.com/problems/find-eventual-safe-states/description/

//cycle detection in directed graph
#include <bits/stdc++.h>

using namespace std;
class Solution {
    bool dfsCheck(int node,vector< vector<int>> &graph, vector<int> &vis, vector<int> &pathvis,int check[])
    {
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for (int i = 0; i< graph[node].size(); i++)
        {   int it = graph[node][i];
            if (!vis[it])
            { // not visited
                if (dfsCheck(it, graph, vis, pathvis,check) == true)
                {
                    check[node] = 0; //as it is a cycle
                    return true;
                }
            }

            //if node has been previously visited on the same path then it is a cycle
            //if it is visited on a different path then pathvis will be 0
            else if(pathvis[it]){
                check[node] = 0;
                return true;
            }
        }
    //if reach here that means not find a cycle so it is safe
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        int check[V] = {0};
        vector<int>safeNodes;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, graph, vis, pathvis,check);    
            }    
        }
        for(int i = 0;i<V;i++){
            if(check[i] == 1){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
int main(){
    
    return 0;
}

//terminal node - outdegree is 0  no element in adjacency list 
//go 0 to V
//at 0 start come back t 0 not safe
//for 1 to 0 to 3 to 1 so not terminal not safe
// to be safe all path going out of 1 should reach terminal not happen here
//so can say if there is a cycle that node not safe(part of cycle) and anything connected to it can return back in cycle not be safe(any one incoming to the cycle)---- cycle detection method 