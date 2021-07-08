#include <iostream>
using namespace std;

struct node {
    int data;
    node * next;
};

void print(node*head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

ostream& operator<<(ostream& io, node * head) {
    print(head);
    return io;
}

int main() {
    node * head = new node();
    node * head2 = new node();
    head->data = 1;
    head2->data = 3;
    cout<<head<<head2;
    return 0;
}