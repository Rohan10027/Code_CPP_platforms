/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    unordered_map<Node*, int> dp;

    int recursive(Node *root) {
        if (!root) return 0;
        if (dp[root]) return dp[root]; 

        int skip1 = recursive(root->left);
        int skip2 = recursive(root->right);

        int a = 0, b = 0, c = 0, d = 0;
        if (root->left) {
            a = recursive(root->left->left);
            b = recursive(root->left->right);
        }
        if (root->right) {
            c = recursive(root->right->left);
            d = recursive(root->right->right);
        }

        int include = root->data + a + b + c + d;
        int exclude = skip1 + skip2;

        return dp[root] = max(include, exclude);
    }

    int getMaxSum(Node *root) {
        return recursive(root);
    }
};
