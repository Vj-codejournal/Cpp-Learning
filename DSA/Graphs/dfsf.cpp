// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;

// #define endl '\n'
// #define MOD 1000000007
// #define all(x) begin(x), end(x)

// ll power_mod(ll base, ll power, ll mod) {
//     ll result = 1;
//     base = base % mod;
//     while (power > 0) {
//         if (power % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         power = power / 2;
//     }
//     return result;
// }

// int play(vi &arr, int my_cow) {
//     vi game(arr.size());
//     game[0] = 0;
//     game[1] = max(arr[0], arr[1]);
//     for(int i=2;i<arr.size();i++) {
//         game[i] = max(game[i-1], arr[i]);
//     }
//     int cnt = count(all(game), my_cow);
//     return cnt;
// }


// void solve() {
//     ll n,k;
//     cin>>n>>k;
//     ll arr[n];
//     for(int i = 0;i<n;i++) {
//         cin>>arr[i];
//     }
//     int i = 0,j = n-1;
//     while(k > 0 && i<=j){
//         int temp1 = k - arr[i];
//         k -= arr[i];
        
//         if(k <= 0 && temp1 != 0){
//             cout<< n - (j - i + 1)<<endl;
//             return;
//         }
//         else if(k == 0 && temp1 == 0){
//             cout<< n - (j - i)<<endl;
//             return;
//         }
//         i++;
//         int temp2= k - arr[j];
//         k -= arr[j];
//         if(k <= 0 && temp2 != 0){
//             cout<< n - (j - i + 1)<<endl;
//             return;
//         }
//         else if(k == 0 && temp2 == 0){
            
//             cout<< n - (j - i)<<endl;
//             return;
//         }


//         j--; 
//     }
//     if(k >=0){
//         cout<<n<<endl;
//     }
// }


// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
     
//     int testcases;
//     cin >> testcases;
//     while(testcases--) {
//         solve();
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>
// using namespace std;

// typedef long long ll;
// int shipsSunk(int n, int k, std::vector<ll>& a) {
//     int i = 0;
//     while (k > 0 && a.size() > 0) {
//         if (i % 2 == 0) {
//             if (a[0] == 0) {
//                 a.erase(a.begin());
//             } else {
//                 a[0]--;
//                 if (a[0] == 0) {
//                     a.erase(a.begin());
//                 }
//             }
//         } else {
//             if (a[a.size() - 1] == 0) {
//                 a.pop_back();
//             } else {
//                 a[a.size() - 1]--;
//                 if (a[a.size() - 1] == 0) {
//                     a.pop_back();
//                 }
//             }
//         }
//         k--;
//         i++;
//     }
//     return n - a.size();
// }

// int main() {
//     int t;
//     cin>>t;
//     while(t-- > 0){
//         ll n,k;
//         cin>>n>>k;
//         vector<ll> a(n);
//         for(int i = 0;i<n;i++){
//             cin>>a[i];
//         }
//         std::cout << shipsSunk(n, k, a) << std::endl;
//     }
    
   

//     return 0;
// }


/*
int size = 0, k = 0;
    cin >> size >> k;
    vi arr(size);
    for(auto &it:arr) {
        cin >> it;
    }

    int my_cow = arr[k-1];
    // case1 : place mycow at front
    swap(arr[0], arr[k-1]);
    int cnt1 = play(arr, my_cow);
    swap(arr[0], arr[k-1]);

    // case 2: no swap
    int cnt2 = play(arr, my_cow);

    // case 3: swap with first value greater than my_cow coming before my cow
    int index = 0;
    for(int i=0;i<k-1;i++) {
        if(arr[i] > arr[k-1]) {
            index = i;
            break;
        }
    }
    swap(arr[index], arr[k-1]);
    int cnt3 = play(arr, my_cow);
    cout << max({cnt1, cnt2, cnt3}) << endl;
*/

// #include <bits/stdc++.h>

// using namespace std;
// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         int count = 0;
//         vector<pair<int,int>> ans;
//         int i = 0,j= arr.size()-1;
//         ans.push_back({arr[i],arr[j]});
//         count++;
//         int l = 0,m = arr.size()-1;
//         while((static_cast<double>(arr[i+1])/arr[j]) != (static_cast<double>(arr[l])/arr[m-1])){
            
//             if(static_cast<double>(static_cast<double>(arr[i+1])/arr[j]) > static_cast<double>(static_cast<double>(arr[l])/arr[m-1])){
//                 ans.push_back({arr[l],arr[m-1]});
//                 m--;
                
//             }
//             else{
//                 ans.push_back({arr[i+1],arr[j]});
//                 i++;
//                 count++;
//             }
            
//         }
//         while(m<i){
//             ans.push_back({arr[m],arr[i]});
//             m++;
//             i--;
//         }

//         for(int x = 0;x<ans.size();x++){
//             if(x == k-1){
//                 return {ans[x].first,ans[x].second};
//             }
//             //cout<<ans[x].first<<" "<<ans[x].second<<endl;
//         }

//         return {-1,-1};

//     }
// };
// int main(){
//     vector<int> arr = { 1,2,3,5};
//     int k = 3;

//     Solution s;
//     cout<<s.kthSmallestPrimeFraction(arr,k)[0]<<endl;
//     return 0;
// }




// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll; 
// typedef vector<int> vi;
// typedef vector<ll> vll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;

// #define endl '\n'
// #define MOD 1000000007
// #define all(x) begin(x), end(x)

// ll power_mod(ll base, ll power, ll mod) {
//     ll result = 1;
//     base = base % mod;
//     while (power > 0) {
//         if (power % 2 == 1) {
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod;
//         power = power / 2;
//     }
//     return result;
// }

// int play(vi &arr, int my_cow) {
//     vi game(arr.size());
//     game[0] = 0;
//     game[1] = max(arr[0], arr[1]);
//     for(int i=2;i<arr.size();i++) {
//         game[i] = max(game[i-1], arr[i]);
//     }
//     int cnt = count(all(game), my_cow);
//     return cnt;
// }

// bool checker(vi &arr) {
//     if(arr[0] == 0 && arr[1] == 0 && arr[2] %2 != 0) {
//         return false;
//     }
//     else if(arr[0] == 0 && arr[1] == 0 && arr[2] %2 == 0){
//         arr[2] = 0;
//         return false;
//     }
//     else if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0){
//         return false;
//     } 
    
//     return true;
// }



// void solve() {
//     int n,m;
//     cin>>n>>m;

//     cin.ignore();

//     string s;
//     getline(cin,s);

//     vi arr(7,0);

//     for(int i = 0;i<n;i++){
//         if(s[i] == 'A') {
//             arr[0]++;
//         }
//         else if(s[i] == 'B') { arr[1]++;}
//         else if(s[i] == 'C') {arr[2]++;}
//         else if(s[i] == 'D') {arr[3]++;}
//         else if(s[i] == 'E') {arr[4]++;}
//         else if(s[i] == 'F') {arr[5]++;}
//         else if(s[i] == 'G') {arr[6]++;}

//     }
//     int count = 0;
//     for(int i = 0;i<7;i++){
//         if(arr[i]<m){
//             count += abs(arr[i] - m);
//         }
//     }

//     cout<<count<<endl;

// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
     
//     int testcases;
//     cin >> testcases;
//     //cin.ignore();

//     while(testcases--) {
//         solve();
//     }
//     return 0;
// }


// #include <iostream>
// #include <vector>

// using namespace std;

// int countWays(int N, int K) {
//     if (K < 1 || K > N) return 0; // If K is out of bounds
//     vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
//     dp[1][1] = 1;

//     for (int n = 2; n <= N; ++n) {
//         for (int k = 1; k <= n; ++k) {
//             dp[n][k] = dp[n-1][k];
//             if (k > 1) {
//                 dp[n][k] += dp[n-1][k-1];
//             }
//             dp[n][k] %= 1000000007; // To prevent overflow and keep the numbers manageable
//         }
//     }
    
//     return dp[N][K];
// }

// int main() {
//     int N, K;
//     cin >> N >> K;
//     cout << countWays(N, K) << endl;
//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> // For std::gcd (C++17 and above)
#include<bits/stdc++.h>

using namespace std;

// Function to find the LCM of two numbers
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

// Function to count the maximum valid pairs
int max_valid_pairs(int N, vector<int> A) {
    int count = 0;
    // Sort the array to optimize the search for LCM*HCF
    sort(A.begin(), A.end());

    // Iterate through all pairs
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int hcf = gcd(A[i], A[j]);
            int product = lcm(A[i], A[j]) * hcf;
            // Binary search to check if the product exists in the array
            if (binary_search(A.begin(), A.end(), product)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    cout << "Enter the size of the array: ";
    cin >> N;

    vector<int> A(N);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << "Maximum number of valid (i,j) pairs: " << max_valid_pairs(N, A) << endl;

    return 0;
}