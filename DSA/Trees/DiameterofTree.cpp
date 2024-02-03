//longest path between any two nodes
/*
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4 
can get diameter 3 ways - in left sub tree only,in right sub tree only ,combo of left and right
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }

        int left = height(node->left);

        int right = height(node->right);

        int ans  = max(left,right) + 1;
        return ans;
    }
    int diameter(Node* root) {
        if(root == NULL){
            return 0;
        }

        int op1 = diameter(root->left);//only in left part
        int op2 = diameter(root->right);//only in right path
        int op3 = height(root->left)+1+ height(root->right);

        int ans  = max(op1,max(op2,op3));
        return ans;
    }
};
//TC = O(N^2) as dimeter and height recursive call
//optimal approach

class Solution2 {
  public:
    // Function to return the diameter of a Binary Tree.
    int height(struct Node* node){
        if(node == NULL){
            return 0;
        }

        int left = height(node->left);

        int right = height(node->right);

        int ans  = max(left,right) + 1;
        return ans;
    }
    //return height and diameter at same time
    pair<int,int> diameterFast(Node* root){
          if(root == NULL){
            pair<int,int>p = make_pair(0,0);
            return p;
        }

        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        int op1 = left.first;//only in left part
        int op2 = right.first;//only in right path
        int op3 = left.second+1+ right.second;

        pair<int,int> ans;
        ans.first =  max(op1,max(op2,op3));//for diameter
        ans.second = max(left.second,right.second)+1;//for height
        
        return ans;
    }
    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};
//TC = O(n);
//SC = O(H) maximum function call stack jo bhara hoga and height can max be n in skew tree
//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}

// } Driver Code Ends