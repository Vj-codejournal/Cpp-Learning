//https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> arr3(m+n ,0);
        int k =0;
        int i = 0,j=0;

        while(i<m && j<n){//ek ke pure hone pe ruk jayenge
            if(nums1[i] < nums2[j]){
                arr3[k] = nums1[i];
                k++;
                i++;
            }
            else{
                arr3[k] = nums2[j];
                k++;
                j++;
            }
        }
        while(i<m){//ab koi element bach gaya to usse dal do
            arr3[k] = nums1[i];
            k++;
            i++;
        }
        while(j<n){
            arr3[k] = nums2[j];
            k++;
            j++;
        }
        for(int i=0;i<n+m;i++){
            nums1[i] = arr3[i];
        }

    }
};

int main(){
    vector<int> arr1 = {1,3,5,7,9,0,0,0};
    vector<int> arr2 = {2,4,6};
    Solution s;
    s.merge(arr1,5,arr2,3);

    for(int i = 0;i<8;i++){
        cout<<arr1[i]<<" ";
    }

    return 0;
}
