/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // code here
             if(root==NULL) return 0;
             
             int left = getSize(root->left);
             int right = getSize(root->right);
             
             return 1+left+right;
    }
};
