#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    Heap<int> h;
    int n = 5;
    for(int i = 1; i <= n; i++) {
        // h.insert(i);
        // for(auto x: h.v) {
        //     cout << x << " ";
        // }
        // cout << endl;
    }

    cout << "Removing" << endl;

    while(!h.empty()) {
        cout << h.top() << endl;
        h.pop();
        // for(auto x: h.v) {
            // cout << x << " ";
        // }
        // cout << endl;
    }
}