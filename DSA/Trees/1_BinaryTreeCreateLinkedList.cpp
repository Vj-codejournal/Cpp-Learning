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

// vector<int> inorder(TreeNode* root){
//     vector<int> ans;

//     stack<TreeNode*> st;
//     TreeNode* node = root;

//     while(true){
//         if(node != NULL){
//             st.push(node);
//             node = node->left;
//         }
//         else{
//             if(st.empty() == true){
//                 break;
//             }
//             node = st.pop();
            
//             ans.push_back(node->val);
//             node = node->right;
//         }
//     }
//     return ans;

// }


void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";//node
    preorder(root->left);//left
    
    preorder(root->right);//right

}
// vector<int> preorder(TreeNode* root){
//     vector<int> ans;
//     if(root == NULL) return ans;

//     stack<TreeNode*> st;

//     st.push(root);
//     while(!st.empty()){
//         root = st.top();
//         st.pop();
//         ans.push_back(root->val);
//         if(root->right != NULL){
//             st.push(root->right);
//         }
//         if(root->left != NULL){
//             st.push(root->left);
//         }
//     }
//     return ans;

// }
void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    postorder(root->left);//left
    postorder(root->right);//right
    cout<<root->data<<" ";//node

}

//POSTORDER using iterative 2 stacks
// vector<int> postorder(TreeNode* root){
//     vector<int> ans;
//     if(root == NULL) return ans;

//     stack<TreeNode*> st1,st2;

//     st1.push(root);
//     while(!st1.empty()){
//         root = st1.top();
//         st1.pop();
//         st2.push(root);
//         if(root->left != NULL){
//             st1.push(root->left);
//         }
//         if(root->right != NULL){
//             st1.push(root->right);
//         }
//     }
//     while(!st2.empty()){
//         ans.push_back(st2.top()->val);
//         st2.pop();
//     }

//     return ans;

// }

//POSTORDER using iterative 1 stack
// vector<int> postorder(TreeNode* root){
//     vector<int> ans;
//     if(root == NULL) return ans;
//    stack<TreeNode*> st;
//   TreeNode* curr = root;
// while(curr != NULL || !st.empty()){
//     if(curr != NULL){
//         st.push(curr);
//         curr = curr->left;
//     }
//     else{
//         TreeNode* temp = st.top()->right;
//         if(temp == NULL){
//             temp = st.top();
//             st.pop();
//             ans.push_back(temp->val);
//             while(!st.empty() && temp == st.top()->right){
//                 temp = st.top();
//                 st.pop();
//                 ans.push_back(temp->val);
//             }
//         }
//         else{
//             curr = temp;
//         }
//     }
// }
//}



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