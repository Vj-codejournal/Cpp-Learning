#include<bits/stdc++.h>
using namespace std;
struct Node {
      int val;
      Node *left;
      Node *right;
        Node *next;
      
  };






class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL)return NULL;

        Node* current = root;

        while(current->left != NULL){
            Node * temp = current; //as current is used to move to next level so store its position
            while(current != NULL){//travel through the level
                current->left->next = current->right;//connect its child
                current->right->next = current->next ==NULL?NULL:current->next->left;//if after 3 no 
                //next value in level so 7 cant be connected to nexts child so null it also else connect it
                current = current->next;//go to 2->3 in that level
            }
            current = temp->left;
        }
        return root;

    }
};