#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue {
    stack<T> a;
    stack<T> b;
public:
    void enqueue(T data) {
        while (!b.empty()) {
            int x = b.top();
            b.pop();
            a.push(x);
        }
        
        b.push(data);

        while(!a.empty()) {
            b.push(a.top());
            a.pop();
        }
    }

    bool empty() {
        if(a.empty() && b.empty()) {
            return true;
        }
        return false;
    }

    T dequeue() {
        T x = b.top();
        b.pop();
        return x;
    }
};


int main() {
    Queue<int> q;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        q.enqueue(i);
    }
    
    while(!q.empty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}