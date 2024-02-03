//https://www.codingninjas.com/studio/problems/pair-sum_697295
#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> list;
   
   for(int i=0;i<arr.size();i++){
      
       for(int j=i+1;j<arr.size();j++){
          
           if(arr[i]+arr[j]==s){
                vector<int> ans;
                ans.push_back(min(arr[i],arr[j]));
                ans.push_back(max(arr[j],arr[j]));
               
                list.push_back(ans);
           }
            
       }
   }
   sort(list.begin(),list.end());
   return list;
}
int main(){

    int n,s;
    cin>>n>>s;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> list = pairSum(arr,s);
    for(int i=0;i<list.size();i++){
        for(int j=0;j<list[i].size();j++){
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}