#include <iostream>

struct Node {
  int data;
  Node* left;
  Node* right;
};

int countNodes(Node* root) {
  if (root == nullptr) {
    return 0;
  }

  int leftCount = countNodes(root->left);
  int rightCount = countNodes(root->right);

  return 1 + leftCount + rightCount;
}

int main() {
  Node* root = new Node{10, nullptr, nullptr};
  root->left = new Node{5, nullptr, nullptr};
  root->right = new Node{15, nullptr, nullptr};
  root->left->left = new Node{2, nullptr, nullptr};
  root->left->right = new Node{8, nullptr, nullptr};

  int nodeCount = countNodes(root);
  std::cout << "Number of nodes in the binary tree: " << nodeCount << std::endl;

  return 0;
}
