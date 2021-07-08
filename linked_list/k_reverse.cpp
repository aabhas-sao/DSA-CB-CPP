#include <iostream>
using namespace std;

struct LinkedList {
    int data;
    LinkedList* next;
};

void reverse(LinkedList *& head) {
    LinkedList * prev = NULL;
    LinkedList * curr = head;
    LinkedList * next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev; 
}

void reverseReturnTail(LinkedList *& head) {
    LinkedList * prev = NULL;
    LinkedList * curr = head;
    LinkedList * next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
}

void reverseK(LinkedList *& head, int k) {
    LinkedList * from = head;
    LinkedList * to = head;
    
    int c = k - 1;
    while(to->next != NULL && c--) {
        to = to->next;
    }
    LinkedList * next_k = to->next;
    LinkedList * prev = NULL;
    to->next = NULL;
    reverse(head);
    prev = from;
    from->next = next_k;
    from = from->next;
    c = k - 1;
    to = from;
    if(to == NULL) {
        return;
    }
    while(to->next != NULL && c--) {
        to = to->next;
    }
    while(next_k != NULL) {
        next_k = to->next;
        prev->next = NULL;
        to->next = NULL;
        reverseReturnTail(from);
        swap(from, to);
        prev->next = from;
        to->next = next_k;
        prev = to;
        from = to->next;
        c = k;
        while(to->next != NULL && c--) {
            to = to->next;
        }
    }
}

void display(LinkedList * head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

LinkedList* createLL(int a[], int n) {
    LinkedList* head = new LinkedList();
    head->data = a[0];
    LinkedList* temp = head;
    for(int i = 1; i < n; i++) {
        LinkedList* newNode = new LinkedList();
        newNode->data = a[i];
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void changePtr(LinkedList* head) {
    head->data = 2;
}

int main() {
    int n = 3;
    int k = 1;  
    int a[] = {1, 3, 4};
    LinkedList* head = createLL(a, n);
  
    // reverse(head);
    reverseK(head, k);
    display(head);
}