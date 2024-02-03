/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/
#include<iostream>

using namespace std;
template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL){
        return false;
    }
    if(root->data == x){
        return true;
    }
    bool ans;
    if(root->data >x){
        ans = searchInBST(root->left,x);
    }
    else if(root->data <x){
        ans = searchInBST(root->right,x);
    }
    return ans;
}

//TC is O(logn) and for skewed tree TC is O(n)
//SC is O(H) height of recursion stack can cause TLE so iterative method below

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        else if(temp->data > x){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
}