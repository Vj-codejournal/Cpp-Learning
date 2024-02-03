


#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        int steps = 0;
        vector<int> temp(n);
        for(int i = 0;i<n;i++){
            temp[(i+k)%n] = nums[i];
        }

        nums = temp;
    }
};
int main(){
    
    return 0;
}

//TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int first = nums[0];
        int n = nums.size();

        for(int i =0;i<n;i++){
            if(i<k){
                swap(nums[i],nums[n-k+i]);
            }
            else{
                
                while(nums[k] != first){

                    for(int t = k;t<k-1;t++){
                        swap(nums[t],nums[t+1]);
                    }
                    
                }
            }
        }



    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        if(k<n){
        vector<int> temp;
        for(int i =n-k;i<n;i++){
            temp.push_back(nums[i]);
        }

        for(int i = n-k-1;i>=0;i--){
            swap(nums[i],nums[i+k]);
        }

        for(int i = 0;i<k;i++){
            nums[i] = temp[i];
        }
        }


    }
};