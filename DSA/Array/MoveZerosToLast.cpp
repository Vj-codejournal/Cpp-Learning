//https://leetcode.com/problems/move-zeroes/description/


#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int ptr = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == 0){
                continue;
            }
            else{
                swap(nums[i],nums[ptr]);
                ptr++;
            }
        }
    }
};
int main(){
    
    return 0;
}