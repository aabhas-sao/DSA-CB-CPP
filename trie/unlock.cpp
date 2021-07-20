#include <iostream>
#include <unordered_map>
using namespace std;

void soln(int a[], int b[], int n, int k) {
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++) {
        m[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        if(k <= 0) break;
        if(b[i] > a[i]) {
            m[a[i]] = m[b[i]];
            swap(a[m[b[i]]], a[i]);  
            k--;
        }
    }

    
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    unordered_map<int, int> m;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b[n];

    for(int i = 0; i < n ; i++) {
        b[i] = n - i;
    }
    
    soln(a, b, n, k);

    return 0;
}