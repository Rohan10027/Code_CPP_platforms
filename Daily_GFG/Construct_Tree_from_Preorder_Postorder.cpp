/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    virtual Node* fun(int &i, int &j, vector<int> &pre, vector<int> &post){
        Node *r = new Node(pre[i]);
        i++;
        
        if(r->data == post[j]){
            j++;
            return r;
        }
        
        r->left = fun(i, j, pre, post);
        r->right = fun(i, j, pre, post);
        
        j++;
        return r;
    }
  
    Node *constructTree(vector<int> &pre, vector<int> &post) {
        // code here
        int preI=0, postI=0;
        return fun(preI, postI, pre, post);
    }
};
