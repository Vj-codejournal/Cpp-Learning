//https://leetcode.com/problems/course-schedule/

//ek ke phele doosra hona chaiye is condition of topology sort
// cyclic nahi hona chaiye nahi to fail ho jayga 0 ke liye 1 chaiye 1 karne ke liye 0  then fail so find topo order  == total no of vertices/courses like prac11 
//just detect graph has a cycle or not if cycle not possible to complete the task

/*
1 2
4 3
2 4
4 1
 1 2 4 3  1 -> 2 -> 4 -> 1 it forms a cycle dependeny cant do
*/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int N = numCourses;

        //convert prereq into a adj list
        vector<int>adj[N];
        for(int i = 0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]); //1th wala phele hone chaiye 0th ke to 1th -> 0th hoga adj list mai
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
        return topo.size() == N;
    }
};
int main(){
    
    return 0;
}