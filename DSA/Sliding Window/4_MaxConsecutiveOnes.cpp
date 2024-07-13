//longest subsequence with a condition

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int l = 0,r = 0,maxlen = 0;

        while(r<n){
            if(nums[r] == 0) zeros++;

            if(zeros>k){
                if(nums[l] == 0)zeros--;
                l++;
            }

            if(zeros <= k){//only update if no  of zeros less than k
                int len = r-l+1;
                maxlen = max(len,maxlen);
            }

            r++;
        }
        return maxlen;
    }
};

/*
not optimized O(2N)
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zeros = 0;
        int l = 0,r = 0,maxlen = 0;

        while(r<n){
            if(nums[r] == 0) zeros++;

            while(zeros>k){
                if(nums[l] == 0)zeros--;
                l++;
            }

            if(zeros <= k){
                int len = r-l+1;
                maxlen = max(len,maxlen);
            }

            r++;
        }
        return maxlen;
    }
};
*/