/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (head1 == NULL || head2 == NULL) 
            return NULL;
        Node *x1 = head1;
        Node *x2 = head2;
        while (x1 != x2) {
            x1 = (x1 == nullptr) ? head2 : x1->next;
            x2 = (x2 == nullptr) ? head1 : x2->next;
        }
        return x2;
    }
};
