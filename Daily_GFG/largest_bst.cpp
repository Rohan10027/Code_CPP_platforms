/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    array<int, 4> dfs(Node* n) {
        if (!n) return {INT_MAX, INT_MIN, 0, 0};
        
        auto l = dfs(n->left);
        auto r = dfs(n->right);
        
        if (l[2] >= 0 && r[2] >= 0 && l[1] < n->data && n->data < r[0]) {
            int sz = l[2] + r[2] + 1;
            return {min(n->data, l[0]), max(n->data, r[1]), sz, sz};
        }
        
        return {0, 0, -1, max(l[3], r[3])};
    }
    
    int largestBst(Node* root) {
        return dfs(root)[3];
    }
};
