//read in post order

#include <iostream>
#include<map>
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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}


class Solution{
    public:

    int findPosition(int in[],int element,int n){
        for(int i = 0;i<n;i++){
            if(in[i] == element){
                return i;
            }

        }
        return -1;
    }
    //optimise findPosition
    void createMapping(int in[],map<int,int> &nodeToIndex ,int n){
            for(int i = 0;i<n;i++){
                nodeToIndex[in[i]] = i;
            }
    }

    Node* solve(int in[],int pre[],int &index, int inOrderStart,int inOrderEnd,int n,map<int,int> &nodeToIndex){

        if(index >= n || inOrderStart>inOrderEnd){//preOrder array completed
            return NULL;
        }
        int element = pre[index++];

        Node * root = new Node(element);
        //int position = findPosition(in,element,n);
        int position = nodeToIndex[element];
        root->left = solve(in,pre,index,inOrderStart,position-1,n,nodeToIndex);
        root->right = solve(in,pre,index,position+1,inOrderEnd,n,nodeToIndex);

        return root;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int,int>nodeToIndex;//Optimise
        createMapping(in,nodeToIndex,n);
        Node * ans = solve(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
        return ans;
    }
};

int main(){
    
    return 0;
}

//in inorder and postorder given case do last of postorder is root as compared to first in pre rest is same and right part is called first then left 
