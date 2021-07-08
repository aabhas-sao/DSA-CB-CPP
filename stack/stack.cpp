#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class StackLL {
    private:
        node * head;
    public:
        void push(int val);
        void pop();
        void display();
        int peek();
};

int StackLL::peek() {
    if(head == NULL) {
        return -1;
    }
    return head->data;
}

void StackLL::push(int val) {
    node * newNode = new node();
    newNode->data = val;
    if(head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void StackLL::pop() {
    if(head == NULL) {
        return;
    }
    node * toDelete = head;
    head = head->next;
    delete toDelete;
}

void StackLL::display() {
    node * temp = head;
    while(head != NULL) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

class StackArray {
    private:
        int a[100];
        int top = -1;
    public:
        void display();
        void push(int val);
        void pop();
        int peek();
};  

void StackArray::display() {
    for(int i = 0; i <= top; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void StackArray::push(int val) {
    a[++top] = val;
}

void StackArray::pop() {
    a[top--];
}

int StackArray::peek() {
    return a[top];
}

int main() {
    // StackArray s = StackArray();
    StackLL s = StackLL();
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek()<<" ";
    s.pop();
    s.push(4);
    s.display();
    return 0;
}