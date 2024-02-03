// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>

using namespace std;

class Solution
{
    bool dfsCheck(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            { // not visited
                if (dfsCheck(it, adj, vis, pathvis) == true)
                    return true;
            }

            //if node has been previously visited on the same path then it is a cycle
            //if it is visited on a different path then pathvis will be 0
            else if(pathvis[it]){
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfsCheck(i, adj, vis, pathvis) == true)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}

//dfs TC = O(V + E) as every node visited once in directed so not 2E

//to use one array pathvis represent by 2 and vis by 1