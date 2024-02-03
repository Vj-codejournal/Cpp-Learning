//https://leetcode.com/problems/subsets/

//pointer on each element exclude or include it



#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> output,int index,vector<int> nums){
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        //exclude
        solve(ans,output,index+1,nums);

        //include
        int element = nums[index];
        output.push_back(element);
        solve(ans,output,index+1,nums);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(ans,output,index,nums);

        return ans;
    }
};
int main(){
    
    return 0;
}

/*
{1,2,3}

1 
exclude    include
{}         {1}
2
exclude     include
{}  {1}     {2} {1,2}
3
exclude           include
{} {1} {2} {1,2}    {3} {1,3} {2,3} {1,2,3}

*/