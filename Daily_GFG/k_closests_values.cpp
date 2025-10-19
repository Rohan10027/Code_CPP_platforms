/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root, vector<int>& v){
        if(!root) return;
        
        dfs(root->left, v);
        v.push_back(root->data);
        dfs(root->right, v);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> v;
        dfs(root, v);
        
        sort(v.begin(), v.end(),[target](int& a, int & b){
            int da = abs(target - a);
            int db = abs(target - b);
            if (da != db) return da < db;
            return a < b; 
        });
        
        vector<int> ans;
        for(int i = 0;i<k && i<v.size();i++) ans.push_back(v[i]);
        
        return ans;
    }
};
