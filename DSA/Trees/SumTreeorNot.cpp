#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
class Solution
{
    public:
    bool isSumTree(Node* root)
    {
         if(root == NULL)
         return true;

        bool left = isSumTree(root->left);
        bool right = isSumTree(root->right);
        bool curr = true;
        if(root->left != NULL && root->right != NULL)
         curr = root->data == root->left->data + root->right->data;

        if(curr&& left && right){
            return true;
        }
        else{
            return false;
        }
    }
};

class sol2{
    public:

    pair<bool,int> isSumFast(Node* root){
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0);
            return p;
        }

        if(root->left == NULL && root-> right == NULL){
            pair<bool,int> p = make_pair(true,root->data);
            return p;
        }

        pair<bool,int> leftAns = isSumFast(root->left);
        pair<bool,int> rightAns = isSumFast(root->right);
        //check left is a sumtree,right subtree is a sum tree and current sum tree is a sum tree
        bool left = leftAns.first;
        bool right = rightAns.first;

        bool curr = root->data == leftAns.second + rightAns.second;

        pair<bool,int> ans;
        if(left && right && curr){
            ans.first = true;
            ans.second = root-> data+leftAns.second + rightAns.second; //or can do 2* root->data

        }
        else{
            ans.first = false;
        }

        return ans;
    }

    bool isSumTree(Node* root){
        return isSumFast(root).first;
    }
};
int main(){
    
    return 0;
}
//           10 for 10 the complete left tree and right tree sum needed
//         /    to be equal to 10  40 + 30 = 10
//       20      30
//     /   \ 
//    10    10

