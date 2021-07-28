#include <iostream>
#include <stack>
#include <climits>
using namespace std;

void insertAtBottom(stack<int>& s, int d) {
    if(s.empty()) {
        s.push(d);
        return;
    }
    int x = s.top();
    s.pop();
    insertAtBottom(s, d);
    s.push(x);
}

void reverse(stack<int>& s) {
    if(s.empty()) {
        return;
    }
    int x = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, x);
}

int main() {
    stack<int> s;
    int n = 5;
    for(int i = 1; i <= n; i++) {
        s.push(i);
    }

    reverse(s);

    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}