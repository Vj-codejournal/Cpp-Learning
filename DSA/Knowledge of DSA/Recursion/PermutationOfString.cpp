//https://leetcode.com/problems/permutations/

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:

    void solve(vector<int> nums ,vector<vector<int>> &ans,int index){
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }


        for(int j = index;j<nums.size();j++){
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1);
            //backtrack undo the change in nums for next part have to make it abc again for next step 
            swap(nums[index],nums[j]);

        }


    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        int index = 0;

        solve(nums,ans,index);
        return ans;
    }
};
int main(){
    
    return 0;
}


/*
abc for 1st step swap a with a the a with b then a with c


       a          b           c
    ab  ac      ba  bc      ca   cb
    abc acb     bac bca    cab    cba
*/ 