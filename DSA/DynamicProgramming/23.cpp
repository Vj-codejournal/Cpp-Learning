#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

bool isConnected(unordered_map<char, unordered_set<char>> &adj, char start, unordered_set<char> &chars) {
    unordered_set<char> visited;
    queue<char> q;
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        for (char neighbor : adj[curr]) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    for (char c : chars) {
        if (visited.find(c) == visited.end()) return false;
    }

    return true;
}

string solution(vector<string> &A) {
    int N = A.size();
    string result(N, '0');
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> inDegree, outDegree;
    unordered_set<char> chars;

    for (int k = 0; k < N; ++k) {
        adj.clear();
        inDegree.clear();
        outDegree.clear();
        chars.clear();

        for (int i = 0; i <= k; ++i) {
            char u = A[i][0], v = A[i][1];
            adj[u].insert(v);
            outDegree[u]++;
            inDegree[v]++;
            chars.insert(u);
            chars.insert(v);
        }

        // Check degree conditions
        int startNodes = 0, endNodes = 0;
        for (char c : chars) {
            if (outDegree[c] - inDegree[c] == 1) startNodes++;
            if (inDegree[c] - outDegree[c] == 1) endNodes++;
        }

        bool degreeCondition = (startNodes == 0 && endNodes == 0) || (startNodes == 1 && endNodes == 1);
        
        // Check connectivity
        bool connectivityCondition = isConnected(adj, A[0][0], chars);
        
        if (degreeCondition && connectivityCondition) {
            result[k] = '1';
        }
    }

    return result;
}

int main() {
    vector<string> A1 = {"he", "ll", "lo", "el"};
    vector<string> A2 = {"ab", "ba", "bq"};
    
    cout << solution(A1) << endl; // Expected output: "1001"
    cout << solution(A2) << endl; // Expected output: "111"

    return 0;
}
