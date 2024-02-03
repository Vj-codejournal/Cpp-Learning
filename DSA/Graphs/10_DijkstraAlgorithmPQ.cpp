#include <bits/stdc++.h>

using namespace std;
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//for min heap
        vector<int> dist(V);
        for(int i = 0;i<V;i++)dist[i] = 1e9;

        dist[S] = 0;
        pq.push({0,S});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;

    }
};
int main(){
    
    return 0;
}

//should not have negative weight cycle for dijkstra as source is dist 0 if -2 and go to 1 then when check again for 1 to 0 become -4 so fill it and become infinite loop

//TC = E log V

//why not queue
/*
extra larger path to reach the same point also considered as not priority so min dist not come first can go to a larger path then come across the smaller path for a queue so extra steps
by priority queue we go minimal path first so longer path automatic rejected when reach them as dist arr already has a smaller value
*/