// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
    
//     vector<pair<int, int>> gifts;
    
//     for (int i = 0; i < m; i++) {
//         int d, v;
//         cin >> d >> v;
//         gifts.push_back({d, v});
//     }
    
//     sort(gifts.begin(), gifts.end());
    
//     long long ans = 0;
//     int currEfficiency = n;
//     vector<bool> used(n+1, false);
    
//     for (int i = 0; i < m; i++) {
//         int day = gifts[i].first;
//         int coinValue = gifts[i].second;
        
//         while (currEfficiency > 0 && day <= n && used[day]) {
//             day++;
//         }
        
//         if (day <= n && currEfficiency > 0) {
//             ans = (ans + (long long)coinValue * currEfficiency) % 1000000007;
//             used[day] = true;
//             currEfficiency--;
//         }
//     }
    
//     cout << ans << endl;

//     return 0;
// }
/*
Bob has invented a machine. The machine has the power to convert coins into candies. Initially, on day 1, the efficiency of the machine is n, that is, a coin with value c produces n x c candies and this efficiency decreases by 1 each day. On day 2, the efficiency is (1) Finally, after n days, the efficiency comes down to 0. The machine cannot accept more than 1 coin in a day. There are m friends who want to give gifts to Bob for inventing the machine. A gift can be described with two integers d and where d is the day on which he or she receives the gift and s is the value of the coin. A coin received on day i can be used on day j if and only if > The same coin cannot be used more than once. Find the maximum possible number of candies that remain with Bob. Input format 1 #include<st 1 The first line contains two integers n and m denoting the number of days, and the number of gifts. 2 #include<st 3 #include<ma 4 The next m lines of input two integers d₁ and v denoting the day and the value of the sth gift. 5vint maximum Output format Print a single Integer denoting the answer to the problem modulo 1000000007 (10° +7) Constraints2 <n<1000001< m < 500000 6 // Write 7 8 } 9 10vint main() 11 int n; 12 scanf(" 13 int m; 14 scanf(" 1<d<n 15 int ig 1≤≤1000 16 give the c++ code
*/
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
    
//     vector<pair<int, int>> gifts;
    
//     for (int i = 0; i < m; i++) {
//         int d, v;
//         cin >> d >> v;
//         gifts.push_back({d, v});
//     }
    
//     sort(gifts.begin(), gifts.end());
    
//     long long ans = 0;
//     int currEfficiency = n;
//     vector<bool> used(n+1, false);
    
//     for (int i = 0; i < m; i++) {
//         int day = gifts[i].first;
//         int coinValue = gifts[i].second;
        
//         while (currEfficiency > 0 && day <= n && used[day]) {
//             day++;
//         }
        
//         if (day <= n && currEfficiency > 0) {
//             ans = (ans + (long long)coinValue * currEfficiency) % 1000000007;
//             used[day] = true;
//             currEfficiency--;
//         }
//     }
    
//     cout << ans << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int alternatingFunction(vector<int> arr) {
//     int n = arr.size();
//     vector<int> dp(n+1, 0);
    
//     for (int i = 1; i <= n; i++) {
//         dp[i] = dp[i-1] + (i % 2 == 0 ? -1 : 1) * arr[i];
//     }
    
//     int maxSum = 0;
//     int minVal = 0;
    
//     for (int i = 1; i <= n; i++) {
//         maxSum = max(maxSum, dp[i] - minVal);
//         minVal = min(minVal, dp[i]);
//     }

//     return maxSum;
// }

// int main() {
//     int t;
//     cin>>t;
//     while(t-->0){
//         int n;
//     cin >> n;
    
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
    
//     int result = alternatingFunction(arr);
    
//     cout << result << endl;
//     }
    

//     return 0;
// }

// #include <iostream>
// #include <queue>

// using namespace std;

// struct Pair {
//     int first;
//     int second;
//     Pair(int first, int second) : first(first), second(second) {}
//     bool operator<(const Pair& other) const {
//         return second < other.second;
//     }
// };

// int main() {
//     int n, g;
//     cin >> n >> g;
    
//     priority_queue<Pair> pq;
    
//     for (int i = 1; i <= g; i++) {
//         int f, s;
//         cin >> f >> s;
//         pq.push(Pair(f, s));
//     }
    
//     long long ans = 0;
//     long long eff = n;
    
//     for (int i = 1; i <= n; i++, eff--) {
//         int f = pq.top().first;
//         int s = pq.top().second;

//         if (f > i) {
//             continue;
//         } else {
//             ans += (eff * s)%1000000007;
//             pq.pop();
//         }
//     }
    
//     cout << ans << endl;

//     return 0;
// }

#include <iostream>
#include <vector>

int medianOfThree(std::vector<int>& arr, int left, int right) {
    int mid = left + (right - left) / 2;
    if (arr[right] < arr[left])
        std::swap(arr[left], arr[right]);
    if (arr[mid] < arr[left])
        std::swap(arr[left], arr[mid]);
    if (arr[right] < arr[mid])
        std::swap(arr[mid], arr[right]);
    return mid;
}

int partition(std::vector<int>& arr, int left, int right) {
    int pivotIndex = medianOfThree(arr, left, right);
    int pivotValue = arr[pivotIndex];
    std::swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivotValue) {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    std::swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

void quickSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    std::vector<int> arr = {12, 4, 5, 6, 7, 3, 1, 15, 8, 10};
    
    quickSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}