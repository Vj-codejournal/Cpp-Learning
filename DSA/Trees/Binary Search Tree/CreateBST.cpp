#include <iostream>
#include<queue>
using namespace std;
class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};
Node* insertIntoBST(Node* &root, int data){
    //base case
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(data > root->data){
        root->right = insertIntoBST(root->right, data);
    }
    else{
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}
void takeInput(Node* &root){
    int data;
    cin>>data;
    
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
        
}
void levelOrderTraversal(Node* root){
    queue <Node*> q;
    q.push(root);

    q.push(NULL);//enter as to seperate the levels 
    //use NULL seperator here
    while(!q.empty()){
        Node* temp = q.front();
        // cout<<temp->data<<endl;// not here as it queue can have null also which cause problem
        q.pop();
        if(temp == NULL){//purana level complete traverrse ho chuka hai
            cout<<endl;
            if(!q.empty()){//queue still has some child nodes
                q.push(NULL); //in queue pushed null
            }
        }
        else{
            cout<<temp->data<<endl;
            if(temp->left){//if not null then true so push then
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
Node* minVal(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    levelOrderTraversal(root);
    
    //in pre post same

    cout<<"Minimum value in BST is: "<<minVal(root)->data<<endl;
    cout<<"Maximum value in BST is: "<<maxVal(root)->data<<endl;
    //50 20 70 10 30 90 110 -1
    return 0;
}

//Time Complexity: O(log n) for insertion same as binary search but for skew O(n)

//inorder for BST is in ascending order
//so minimum is at the left most of the tree and maximum is at the right most

//how to find in order predessor?
//how to find in order successor?