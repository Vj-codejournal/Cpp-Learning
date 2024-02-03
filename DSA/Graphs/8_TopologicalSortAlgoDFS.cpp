//https://www.geeksforgeeks.org/problems/topological-sort/1
#include <bits/stdc++.h>

using namespace std;

class Solution
{   
    void dfs(int node,vector<int> adj[],int vis[],stack<int> &st){
        vis[node] = 1;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis,st);
            }
        }
        st.push(node);
    
}
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    int vis[V] = {0};
        stack<int> st;
        vector<int>ans;
        for(int i =0;i<V;i++){
            if(!vis[i])
                dfs(i,adj,vis,st);
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
	}
};
int main(){
    
    return 0;
}

//SC - O(N+N) = O(N)

//TC - O(V+E) same as dfs

