#include <iostream>
#include <queue>

using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = nullptr;
        this->right = nullptr;
        
    }
};
//can do by class also

//by recursion
node* buildTree(node * root){ //when user defined function create use *
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){//break at -1
        return NULL;
    }

    cout<<"Enter data for inserting at left"<<endl;
    root->left = buildTree(root->left);//recurssion
    cout<<"Enter data for inserting at right"<<endl;
    root->right = buildTree(root->right);//recurssion

    return root;//root ptr to return pointing at the root node


}

void levelOrderTraversal(node* root){
    queue <node*> q;
    q.push(root);

    q.push(NULL);//enter as to seperate the levels 
    //use NULL seperator here
    while(!q.empty()){
        node* temp = q.front();
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
//recursion
void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);//left
    cout<<root->data<<" ";//node
    inorder(root->right);//right

}
void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";//node
    inorder(root->left);//left
    
    inorder(root->right);//right

}
void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    inorder(root->left);//left
    inorder(root->right);//right
    cout<<root->data<<" ";//node

}

void buildFromLevelOrder(node * &root){
    queue<node*>  q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        cout<<"Enter left node for:"<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for:"<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main(){
    node * root = nullptr;

    //creating tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order 
    cout<<"Printing Level order traversal output"<<endl;
    levelOrderTraversal(root);

    cout<<"inorder traversal is: ";
    inorder(root);
    cout<<"preorder traversal is: ";
    preorder(root);
    cout<<"postorder traversal is: ";
    postorder(root);

    return 0;
}