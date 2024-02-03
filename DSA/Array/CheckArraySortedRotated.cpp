//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
//if it was sorted then arr[i]> arr[i+1] will be at a single position as{3,4,5,1,2} can see 5 to one is the only place but if find 2 or more places where it  happen then cant be soted
//but if{1,1,1} then count = 0 so still sorted 
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i%n] >nums[(i+1)%n] ){
                count++;
            }

        }
        if(count <= 1){
            return true;
        }
        else return false;
    }
};
int main(){
    
    return 0;
}


/*
class Solution {
public:
    bool check(vector<int>& nums) {
        int min = 0;
        int n = nums.size();
        if(n == 0 || n == 1){
            return true;
        }
        for(int i = 1;i<n;i++){
            if(nums[min]>nums[i]){
                min = i;
            }
        }
        bool flag = false;
        for(int i = min;(i+1)%n != min;i = (i+1)%n){
            if(nums[i%n] <= nums[(i+1)%n] || (nums[(i+1)%n] == nums[min] && nums[(i+2)%n] == nums[min])){
                    flag = true;
            }
            else{
                flag = false;
                break;
            }
        }

        return flag;
    }
};
*/