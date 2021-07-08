#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s1, int x) {
    if(s1.empty()) {
        s1.push(x);
        return;
    }
    int d = s1.top();
    s1.pop();
    insertAtBottom(s1, x);
    s1.push(d);
}

void reverseStackRecursive(stack<int>& s1) {
    // base case
    if(s1.empty()) {
        return;
    }

    int x = s1.top();
    s1.pop();
    reverseStackRecursive(s1);
    insertAtBottom(s1, x);
}

void reverseStack(stack<int>& s1, stack<int>& s2) {
    int n = s1.size();
    for(int i = 0; i < n - 1; i++) {
        int up = s1.top();
        s1.pop();

        // s1 to s2
        for(int i = 0; i < n - 1 - i; i++) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(up);

        // from s2 back to s1
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
}

int main() {
    stack<int> s1;
    stack<int> s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    // reverseStack(s1, s2);
    // reverseStackRecursive(s1);
    // cout<<s1.top()<<endl;
    while(!s1.empty()) {
        cout<<s1.top()<<endl;
        s1.pop();
    }
    return 0;
}