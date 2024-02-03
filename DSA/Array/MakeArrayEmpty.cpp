#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> m;

        for(auto it : nums){
            m[it]++;
        }
        int count = 0;
        for(auto it = m.begin();it!= m.end();){
            if(it->second == 1){
                return -1;
            }
            if(it->second%3 == 0 ||(it->second > 3 && it->second %2 != 0)){
                m[it->first] -= 3;
                count++;
                
            }
            else if(it->second%2 == 0){
                m[it->first] -= 2;
                count++;
            }

            if(it->second == 0){
                it++;                
            }
        }
        return count;
    }
};
int main(){
    vector<int> nums = {2,3,3,2,2,4,2,3,4};
    //[19,19,19,19,19,19,19,19,19,19,19,19,19]
    Solution s;
    cout<<s.minOperations(nums);
    return 0;
}