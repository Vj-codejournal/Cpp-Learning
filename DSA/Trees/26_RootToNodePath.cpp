#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

bool getPath(TreeNode* A,int B,vector<int> &ans){
    if(A == NULL){
        return false;
    }
    if(A->val == B){
        ans.push_back(A->val);
        return true;
    }
    if(getPath(A->left,B,ans) || getPath(A->right,B,ans)){//if any of them is true
        
        return true;
    }
    ans.pop_back();//else
    return false;
}

vector<int> solve(TreeNode* A,int B){
    vector<int> ans;
    if(A == NULL){
        return ans;
    }
    getPath(A,B,ans);
    return ans;
}