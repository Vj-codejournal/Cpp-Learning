#include <bits/stdc++.h>
using namespace std;

bool is_valid(vector<char> &p, int n) {
    int rover_count = 0;
    int helicopter_count = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 'R') {
            rover_count++;
        } else if (p[i] == 'H') {
            helicopter_count++;
        }
    }
    return rover_count == helicopter_count;
}

void solve() {
   
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
    }
    return 0;
}