/*                      need height for 2 it will be
    2                   if left sub tree of 2 is h1
  /  \                  and right sub tree is h2
 4    1                 then max(h1,h2) + 1
     /                  continue recurssion
    3
*/
#include <iostream>

using namespace std;
// struct Node
// {
//     int data;
//     struct Node* left;
//     struct Node* right;
// };
//  struct Node* newNode(int val)
// {
//     struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));;
//     temp->data = val;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }

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
class Solution{
    public:
    
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }

        int left = height(node->left);

        int right = height(node->right);

        int ans  = max(left,right) + 1;
        return ans;
    }
};
int main(){
     
    return 0;
}

//TC O(n) go through all n nodes
//SC O(height) that is stored in stack to calc height worst for skew tree O(n)
