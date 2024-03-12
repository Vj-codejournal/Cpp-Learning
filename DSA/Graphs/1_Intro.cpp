/*
Input will have n m represent nodes and vertices
next m lines of input will give the connection like 2 1 so vertex 2 and 1 are connected 

this can be stored in 2 ways 
1)adjacency matrix SC = O(nxn) costly
2)list 

for list

make a array of vectors
if 5 vertices

make

0
1 -> {2,3} as 2 and 3 are adjacent to 1 so store
2 -> {1,4,5}
3 -> {1,4}
4 -> {2,3,5}
5 -> {2,4}

see 12 storage that is 2*Edges
 SC(2E)
*/
//Undirected

//adjacency matrix
#include <iostream>

using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    int adj[n+1][m+1];

    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u][v] = 1;
        adj[v][u] = 1;



    }
    return 0;
}

//list
#include <iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;

    cin>>n>>m;
    vector<int> adj[n+1];

    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);//in directed this not come so SC O(E)



    }
    return 0;
}

//for weighted in adjecency matrix store the weight in place of 1

//for list store pair<int,int> 

//can store adj list in a map int ,list