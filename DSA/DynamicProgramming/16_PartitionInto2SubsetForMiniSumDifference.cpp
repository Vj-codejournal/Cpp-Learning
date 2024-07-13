//this work only when divided arrays not need to be of equal size

//class Solution {
// public:
//     int minimumDifference(vector<int>& nums) {
//         int n = nums.size();
//         int totsum = 0;
//         for(int i = 0;i<n;i++){
//             totsum += nums[i];    
//         }
//         int k = totsum;
//         vector<vector<bool>> dp(n,vector<bool>(k+1,0));//now need no -1 can take bool dp array
//         for(int i = 0;i<n;i++){
//             dp[i][0] = true;
//         }//for any ind if target is 0 then true
//         if(nums[0] <= k) dp[0][nums[0]] = true;//if only one element and target is same as that element then true
//         for(int ind = 1;ind<n;ind++){
//             for(int target = 1;target<=k;target++){
//                 bool notTake = dp[ind-1][target];
//                 bool take = false;
//                 if(nums[ind] <= target){
//                     take = dp[ind-1][target-nums[ind]];
//                 }
//                 dp[ind][target] = take | notTake;
//             }
//         }

//         //return dp[n-1][sum];
//         int mini = 1e9;
//         for(int s1=0 ;s1<totsum/2;s1++){
//             if(dp[n-1][s1] == true){
//                 mini = min(mini,abs((totsum - s1) - s1));
//             }
//         }
//         return mini;
//     }
// };