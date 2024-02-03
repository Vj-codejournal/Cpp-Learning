//https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/

#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        
        vector<vector<int>> ans;
        //int i = 0;
        bool flag = false;
        while(true){
            vector<int> temp;
            for(auto it : mp){
                
                if(it.second != 0){
                    //cout<<"Entered "<< i<<endl;
                    temp.push_back(it.first);
                    //ans[i].push_back(it.first);
                    mp[it.first]--;
                    flag = true;
                }
                //cout<<it.first<<" "<<it.second<<endl;
                
            }

            
            if(flag){
                ans.push_back(temp);
                
                flag = false;
            }
            else{
                break;
            }
        }

        return ans;
    }
};
int main(){
    vector<int> nums = {1,3,4,1,2,3,1};

    Solution s;
    vector<vector<int>> ans = s.findMatrix(nums);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}