//longest subsequence with a condition
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //map take log time use hasharray O(1) time
        int hash[256]; //all char are index acc to their ascii value in in arr we store its index in the string
        for(int i=0; i<256;i++){
            hash[i] = -1;
        }
        int n = s.length();
        int l = 0,r = 0,maxLen = 0;
        while(r<n){
            if(hash[s[r]] != -1){//current char already in map
                if( hash[s[r]] >=l) //it is in range of current substring so have to change l
                l = hash[s[r]] + 1;

            }
        int len = r - l+1;
        maxLen = max(len,maxLen);
        hash[s[r]] = r;
        r++;
        }
        return maxLen;
    }

};