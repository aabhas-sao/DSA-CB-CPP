#include <iostream>
#include <queue>
using namespace std;

int main() {
    // priority_queue<int> pq; // max heap
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    int n = 5;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    return 0;
}