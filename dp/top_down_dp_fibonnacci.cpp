#include <iostream>
#include <unordered_map>
using namespace std;

int fib(int n, unordered_map<int, int>& m) {
    if(n == 0 || n == 1) {
        return n;
    }
    if(m.find(n) != m.end()) {
        return m[n];
    }
    m[n] =  fib(n - 1, m) + fib(n - 2, m);
    return m[n];
}

int main() {
    unordered_map<int, int> m;
    cout << fib(6, m) << endl;
    return 0;
}