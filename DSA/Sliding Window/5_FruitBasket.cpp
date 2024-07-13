//longest subsequence with a condition
//longest substring with at most K distinct char have to maintain a num,freq mapping and check if map elements size is more than k shrink

//brute
/*
for(int i = 0;i<n;i++){
    set<int> st;
    for(int j = i;j<n;j++){
        st.insert(arr[j]);
        if(st.size() > k)break;
        maxlen = max(maxlen,j-i+1);
    }
}
*/

//sliding window

#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {

        int l = 0,r = 0,maxlen = 0;
        map<int,int> mp;

        while(r<N){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[l]]--;
                    if(mp[fruits[l]] == 0)mp.erase(fruits[l]);
                    l++;
                }

            }
            if(mp.size() <= 2){
                maxlen = max(maxlen,r-l+1);
            }
              r++;  
        }
        return maxlen;
    }
};
//TC O(2N) SC O(N)

//more optimize
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) {

        int l = 0,r = 0,maxlen = 0;
        map<int,int> mp;

        while(r<N){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)mp.erase(fruits[l]);
                l++;
                

            }
            if(mp.size() <= 2){
                maxlen = max(maxlen,r-l+1);
            }
              r++;  
        }
        return maxlen;
    }
};