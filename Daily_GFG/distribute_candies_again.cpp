/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int solve(Node* root , int&move , int&blnc){
        
      if(root == NULL)
      return 0;
      
      blnc += root->data-1;
      root->data += (solve(root->left,move,blnc)+solve(root->right, move,blnc));
      if(root->data <= 0)
      move += (root->data-1)*-1;
      else
      move += (root->data-1);
      
    
      return root->data-1;
    }
    
    int distCandy(Node* root)
    {
        int move  = 0 , blnc = 0;
        solve(root , move, blnc);
        
        return move+blnc;
    }
};
