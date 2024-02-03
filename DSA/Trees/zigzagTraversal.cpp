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