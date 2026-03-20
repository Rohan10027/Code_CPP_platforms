/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node*predecessor = nullptr, *temp = root;
        while(temp){
            if(temp->data < key){
                predecessor = temp;
                temp = temp->right;
            }else{
                temp = temp->left;
            }
        }
        temp = root;
        Node*sucessor = nullptr;
        while(temp){
            if(temp->data > key){
                sucessor = temp;
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        return {predecessor, sucessor};
    }
};
