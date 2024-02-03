#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
};

int countInternalNodes(Node* root) {
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    return 0;
  }

  int leftCount = countInternalNodes(root->left);
  int rightCount = countInternalNodes(root->right);

  return 1 + leftCount + rightCount;
}

int main() {
  Node* root = new Node{10, nullptr, nullptr};
  root->left = new Node{5, nullptr, nullptr};
  root->right = new Node{15, nullptr, nullptr};
  root->left->left = new Node{2, nullptr, nullptr};
  root->left->right = new Node{8, nullptr, nullptr};

  int internalNodeCount = countInternalNodes(root);
  std::cout << "Number of internal nodes in the binary tree: " << internalNodeCount << std::endl;

  return 0;
}
