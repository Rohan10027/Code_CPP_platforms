/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
    int buildTree(Node* root, int parentSum) {
        if(root == NULL) return 0;
        
        int rightSum = buildTree(root->right, parentSum);
        int nodeData = root->data;
        
        root->data = rightSum + parentSum;
         
        int leftSum = buildTree(root->left, parentSum + nodeData + rightSum);
        return nodeData + rightSum + leftSum; 
    }
  public:
    void transformTree(Node *root) {
        buildTree(root, 0);
    }
};
