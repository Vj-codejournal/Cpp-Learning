#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 105;

vector<int> primes;
vector<int> adj[MAXN];
bool is_prime[201];
int dp[MAXN][101];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 200; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 200; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= 100; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

void dfs(int node, int parent) {
    for (int prime : primes) {
        dp[node][prime] = 1;
    }
    for (int neighbor : adj[node]) {
        if (neighbor == parent) continue;
        dfs(neighbor, node);
        for (int prime : primes) {
            long long ways = 0;
            for (int neigh_prime : primes) {
                if (!is_prime[prime + neigh_prime]) {
                    ways = (ways + dp[neighbor][neigh_prime]) % MOD;
                }
            }
            dp[node][prime] = (dp[node][prime] * ways) % MOD;
        }
    }
}

int main() {
    sieve();

    int t;
    cin >> t;
    while(t-->0){

    
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dp, 0, sizeof(dp));
    dfs(1, -1);

    long long result = 0;
    for (int prime : primes) {
        result = (result + dp[1][prime]) % MOD;
    }

    cout << result << endl;
    }
    return 0;
}