#include <iostream>
#include <vector>
#include <cstring>

const int MAX_N = 100005;
const int MOD = 1e9 + 7;
const int MAX_PRIME = 100;

std::vector<int> primes;
std::vector<int> adj[MAX_N];
int dp[MAX_N][MAX_PRIME];

void sieve() {
    bool is_prime[MAX_PRIME + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX_PRIME; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}

bool is_prime_sum(int a, int b) {
    int sum = a + b;
    for (int prime : primes) {
        if (prime > sum) break;
        if (sum == prime) return true;
    }
    return false;
}

int dfs(int node, int parent, int parent_value) {
    int result = 0;
    
    for (int prime_index = 0; prime_index < primes.size(); prime_index++) {
        int prime = primes[prime_index];
        
        if (parent == 0 || !is_prime_sum(parent_value, prime)) {
            if (dp[node][prime_index] != -1) {
                result = (result + dp[node][prime_index]) % MOD;
                continue;
            }
            
            long long subtree_result = 1;
            for (int child : adj[node]) {
                if (child != parent) {
                    subtree_result = (subtree_result * dfs(child, node, prime)) % MOD;
                }
            }
            
            dp[node][prime_index] = subtree_result;
            result = (result + subtree_result) % MOD;
        }
    }
    
    return result;
}

int main() {
    sieve();
    memset(dp, -1, sizeof(dp));
    
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int result = dfs(1, 0, 0);
    std::cout << result << std::endl;
    
    return 0;
}