//https://leetcode.com/problems/course-schedule-ii/description/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;

        //convert prereq into a adj list
        vector<int>adj[N];
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        int indegree[N];
        for(int i = 0;i<N;i++){
            indegree[i] = 0;
        }
        for(int i = 0;i<N;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<N;i++){
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
        if(topo.size() != N){
            topo.clear();
        }
        return topo;
    }
};
int main(){
    
    return 0;
}