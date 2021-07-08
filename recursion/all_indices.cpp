#include <iostream>
using namespace std;

void indices(int a[], int n, int m, int i = 0) {
    // base case:
    if(n == 0) {
        return;
    }
    if(a[0] == m) {
        cout<<i<<" ";
    }
    indices(a + 1, n - 1, m, i + 1);
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    int m;
    cin>>m;
    indices(a, n, m);
    return 0;
}