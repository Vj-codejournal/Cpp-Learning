//Breadth First Search Traversal Techinque

 //need a Queue and visited array

 //{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        //it is a 0th indexing graph
        int vis[V] = {0};
        vis[0] = 1; //as this is root node entered in queue

        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            bfs.push_back(node);

            for(auto it : adj[node]){//each node ke liye jo vector list thi wo check hogi //going to the adjecency list
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }

            }

        }
        return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//SC - O(2N)
//TC - O(N) + O(2E) as while loop run for all node and for loop run for all the degrees of each node