#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v};
    }
    int ans = 25; // 25 prime numbers less than or equal to 10^2
    for (int i = 1; i < N; i++) {
        ans = (ans * 24) % MOD; // 24 prime numbers except 2
    }
    ans = (ans + 24) % MOD; // add the case where Node 1 is assigned 2
    cout << ans << endl;
    return 0;
}

