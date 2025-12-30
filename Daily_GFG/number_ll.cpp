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
    Node* reverse(Node *head){
        Node* prev = NULL, *forw = NULL;
        Node * curr = head;
        while(curr != NULL){
            forw = curr->next;
            curr->next = prev;
            prev =  curr;
            curr = forw;
        }
        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        if(!head1) return head2;
        if(!head2) return head1;
        head1 = reverse(head1);
        head2 = reverse(head2);
        int sum = 0;
        int carry = 0;
        Node *temp = NULL,*head = NULL,*tail = NULL;
        while(head1 || head2 || carry){
            sum = carry + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
            carry = sum / 10;
            sum = sum % 10;
            temp = new Node(sum);
            if(!head) head = temp;
            else tail->next = temp;
            tail = temp;
            if(head1) head1 = head1->next;
            if(head2) head2 = head2->next;
        }
        head = reverse(head);
        while(head->data == 0 && head->next){
            head = head->next;
        }
        return head;
    }
};
