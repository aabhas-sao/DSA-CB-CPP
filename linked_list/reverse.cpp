#include <iostream>
using namespace std;

struct node {
    int data;
    node * next;
};

void display(node * head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void reverse(node *& head) {
    node * curr = head;
    node * prev = NULL;
    node * next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    display(head);
}

node * reverseRecursive(node *& head) {
    if(head->next == NULL) {
        return head;
    }
    node * revedHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return revedHead;
}

int main() {
    node * head = new node();
    head->data = 1;
    node * head1 = head;
    int n = 10;
    int i = 2;
    
    while(i <= n) {
        node * temp = new node();
        temp->data = i;
        head1->next = temp;
        head1 = head1->next;
        i++;
    }
    display(head);
    cout<<endl;
    // reverse(head);
    head = reverseRecursive(head);
    cout<<endl;
    display(head);
    return 0;
}