/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    protected:
    int getAns(Node* root, int &count){
        if(!root){
            return -1;
        }
        int left= getAns(root->left, count);
        count--;
        if(count==0){
            return root->data;
        }
        int right= getAns(root->right, count);
        if(left!=-1){
            return left;
        }
       else if(right!=-1){
            return right;
        }
        else{
            return -1;
        }
        
    }
    private:
    void getTotalNuberOfNode(Node* root, int &count){
        if(!root)
        return;
        count++;
        getTotalNuberOfNode(root->left, count);
        getTotalNuberOfNode(root->right, count);
    }
  public:
    int findMedian(Node* root) {
        // Code here
        //Fine the totak numver of noders;
        int count=0;
        getTotalNuberOfNode(root, count);
        if(count&1){
            count= (count+1)/2;
            
        }
        else{
            count= count/2;
        }
        return getAns(root, count);
    }
};
