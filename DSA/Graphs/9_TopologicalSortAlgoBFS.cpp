//Kahn Algorithm for topological sort 

#include <bits/stdc++.h>

using namespace std;

class Solution
{   
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int indegree[V] = {0};
        for(int i = 0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            //node is removed so reduce the indegree of its adjacent nodes
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return topo;
	}
};
int main(){
    
    return 0;
}

//SC - O(N) for queue

//TC - O(V+E) same as bfs each edge and vertex once



