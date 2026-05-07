bool isIdentical(Node* a, Node* b){
        
        if(a == NULL && b == NULL){
            return true;
        }
        
        if(a == NULL || b == NULL){
            return false;
        }
        
        return (a->data == b->data) &&
               isIdentical(a->left, b->left) &&
               isIdentical(a->right, b->right);
    }
  
    bool isSubTree(Node *root1, Node *root2) {
        
        if(root2 == NULL){
            return true;
        }
        
        if(root1 == NULL){
            return false;
        }
        
        if(isIdentical(root1, root2)){
            return true;
        }
        
        return isSubTree(root1->left, root2) ||
               isSubTree(root1->right, root2);
    }
