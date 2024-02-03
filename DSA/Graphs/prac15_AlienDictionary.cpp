//https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>

using namespace std;
class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //if k = 4 means a = 0 b =1 c = 2 d = 3
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            for(int  j = 0;j<min(dict[i].size(),dict[i+1].size());j++){
                if(dict[i][j] != dict[i+1][j]){
                    adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                    break;
            }
        }
        }
        map<int,char> m;
        // int i = 0;
        // char temp = 'a';
        //or make a array
        for(int i = 0;i<26;i++){
        
            m.insert(make_pair(i,static_cast<char>('a'+i)));

        }


        int indegree[K] = {0};
        for(int i = 0;i<K;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0;i<K;i++){
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
        string ans = "";
        for(int i = 0;i<topo.size();i++){
            ans.push_back(m[topo[i]]);
        }

        return ans;
    }
};
int main(){
    
    return 0;
}