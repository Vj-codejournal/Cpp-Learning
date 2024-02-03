#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {   
        if(r1->data == NULL && r2-> data == NULL){
        return true;
    }
        if(r1->data != NULL && r2-> data == NULL){
        return false;
    }
        if(r1->data == NULL && r2-> data != NULL){
        return false;
    }
        
        
    
        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);
        bool currValue = r1->data == r2->data;

        if(left && right && currValue){
        return true;

        }
        else
        return false;
    }
};