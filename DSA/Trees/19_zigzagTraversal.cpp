#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
class sol{
    public:

    vector<int> ZigZagTraversal(Node* root){
        vector<int> result;

        if(root == NULL){
            return result;
        }
        queue<Node*> q;
        q.push(root); 

        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);

            for(int i = 0;i<size;i++){
                Node* frontNode = q.front();
                q.pop();

                int index = leftToRight? i: size - i -1;
                ans[index] = frontNode -> data;

                if(frontNode-> left){//not null
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }

            leftToRight = !leftToRight;

            for(auto i: ans){
                result.push_back(i);
            }

        }
        return result;
    }
};
int main(){
     
    return 0;
}

//in level order at alternate step store in stack

//make flag lefttoright true store left to right false store righttoleft in queue



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> result;
        
//         // Check if the root is NULL,
//         // return an empty result
//         if(root == NULL){
//             return result;
//         }
        
//         // Queue to perform
//         // level order traversal
//         queue<TreeNode*> nodesQueue;
//         nodesQueue.push(root);
        
//         // Flag to determine the direction of
//         // traversal (left to right or right to left)
//         bool leftToRight = true;
        
//         // Continue traversal until
//         // the queue is empty
//         while(!nodesQueue.empty()){
//             // Get the number of nodes
//             // at the current level
//             int size = nodesQueue.size();
            
//             // Vector to store the values
//             // of nodes at the current level
//             vector<int> row(size);
            
//             // Traverse nodes at 
//             // the current level
//             for(int i = 0; i < size; i++){
//                 // Get the front node
//                 // from the queue
//                 TreeNode* node = nodesQueue.front();
//                 nodesQueue.pop();
                
//                 // Determine the index to insert the node's
//                 // value based on the traversal direction
//                 int index = leftToRight ? i : (size - 1 - i);
                
//                 // Insert the node's value at
//                 // the determined index
//                 row[index] = node->val;
                
//                 // Enqueue the left and right
//                 // children if they exist
//                 if(node->left){
//                     nodesQueue.push(node->left);
//                 }
//                 if(node->right){
//                     nodesQueue.push(node->right);
//                 }
//             }
            
//             // Switch the traversal
//             // direction for the next level
//             leftToRight = !leftToRight;
            
//             // Add the current level's
//             // values to the result vector
//             result.push_back(row);
//         }
        
//         // Return the final result of
//         // zigzag level order traversal
//         return result;

//     }
// };