
// #include <bits/stdc++.h>

// using namespace std;
// #define ll long long
// void possibilities(pair<int,char> arr[],int n,int m,int x,set<int> &s,int counter){
//   if(counter == m){
//     s.insert(x);
//     return;
//   }

//   if(arr[counter].second == '0'){
//     if(x+arr[counter].first <= n){
//       x = x+arr[counter].first;
//     }
//     else{
//       x = (x+arr[counter].first)%n;
//     }
//     possibilities(arr,n,m,x,s,counter+1);
//   }
//   else if(arr[counter].second == '1'){
//     if(x-arr[counter].first >0){
//       x = x-arr[counter].first;
//     }
//     else{
//       x = n + x -arr[counter].first;
//     }
//     possibilities(arr,n,m,x,s,counter+1);
//   }
//   else if(arr[counter].second == '?'){
//     int temp = x;
//     if(x+arr[counter].first <= n){
//       x = x+arr[counter].first;
//     }
//     else{
//       x = (x+arr[counter].first)%n;
//     }
//     possibilities(arr,n,m,x,s,counter+1);

//     x = temp;
//     if(x-arr[counter].first >0){
//       x = x-arr[counter].first;
//     }
//     else{
//       x = n + x -arr[counter].first;
//     }
//     possibilities(arr,n,m,x,s,counter+1);
//   }

// }
// int main(){
//     int t;
//     cin>>t;
//     while(t-->0){
//         int n,m,x;
        
//         cin>>n>>m>>x;

//         pair<int,char> arr[m];

//         for(int i=0;i<m;i++){
//             cin>>arr[i].first>>arr[i].second;
//         }

//         set<int> s;
        
//         int counter = 0;
//         possibilities(arr,n,m,x,s,counter);

      

//         cout<<s.size()<<endl;
//         for(auto it:s){
//           cout<<it<<" ";
//         }
//         cout<<endl;

//     }  
//   return 0;
// }


#include <bits/stdc++.h>
using namespace std;

#define ll long long

void possibilities(pair<int,char> arr[],int n,int m,int x,set<int> &s,int counter, unordered_map<string, int>& memo){
    if(counter == m){
        s.insert(x);
        return;
    }

    string key = to_string(counter) + "_" + to_string(x);
    if(memo.find(key) != memo.end()){
        return;
    }

    if(arr[counter].second == '0'){
        if(x+arr[counter].first <= n){
            x = x+arr[counter].first;
        } else{
            x = (x+arr[counter].first)%n;
        }
        possibilities(arr,n,m,x,s,counter+1, memo);
    } else if(arr[counter].second == '1'){
        if(x-arr[counter].first > 0){
            x = x-arr[counter].first;
        } else{
            x = n + x -arr[counter].first;
        }
        possibilities(arr,n,m,x,s,counter+1, memo);
    } else if(arr[counter].second == '?'){
        int temp = x;
        if(x+arr[counter].first <= n){
            x = x+arr[counter].first;
        } else{
            x = (x+arr[counter].first)%n;
        }
        possibilities(arr,n,m,x,s,counter+1, memo);
        x = temp;
        if(x-arr[counter].first > 0){
            x = x-arr[counter].first;
        } else{
            x = n + x -arr[counter].first;
        }
        possibilities(arr,n,m,x,s,counter+1, memo);
    }
    memo[key] = 1;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,m,x;
        cin>>n>>m>>x;
        pair<int,char> arr[m];
        for(int i=0;i<m;i++){
            cin>>arr[i].first>>arr[i].second;
        }
        set<int> s;
        int counter = 0;
        unordered_map<string, int> memo;
        possibilities(arr,n,m,x,s,counter, memo);
        cout<<s.size()<<endl;
        for(auto it:s){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int t;
//     cin>>t;
//     while(t-->0){
//         int n,m,x;
//         cin>>n>>m>>x;
//         vector<pair<int,char>> arr(m);
//         for(int i=0;i<m;i++){
//             cin>>arr[i].first>>arr[i].second;
//         }
//         vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
//         dp[0][x] = true;
//         for(int i=0; i<m; i++){
//             for(int j=0; j<=n; j++){
//                 if(dp[i][j]){
//                     if(arr[i].second != '1'){
//                         dp[i+1][(j+arr[i].first)%n] = true;
//                     }
//                     if(arr[i].second != '0'){
//                         dp[i+1][(j-arr[i].first+n)%n] = true;
//                     }
//                 }
//             }
//         }
//         int count = 0;
//         for(int j=0; j<=n; j++){
//             if(dp[m][j]){
//                 count++;
//             }
//         }
//         cout<<count<<endl;
//         for(int j=0; j<=n; j++){
//             if(dp[m][j]){
//                 cout<<j<<" ";
//             }
//         }
//         cout<<endl;
//     }  
//     return 0;
// }

