#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };




class Solution {
public:
    int ans = 0;
    void solve(TreeNode* root,int digit){
        if(root == nullptr){
           return;
        }

        digit = digit * 10 + root->val;
        if(root->left == NULL && root->right == NULL){
            ans += digit;
            return;
        }

        solve(root->left,digit);
        solve(root->right,digit);


    }
    int sumNumbers(TreeNode* root) {
        
        int digit = 0;
        solve(root,digit);
        return ans;
    }
};