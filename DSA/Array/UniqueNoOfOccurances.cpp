//https://leetcode.com/problems/unique-number-of-occurrences/description/
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     
        
        
        map<int,int> mp;
        
        
        for(auto it:arr)
        {
            mp[it]++;
        }
        
        
        set<int> st;
        
        for(auto it:mp)
        {
            st.insert(it.second);
        }
        
        return st.size()==mp.size();
        
    }
};
int main(){
    
    return 0;
}