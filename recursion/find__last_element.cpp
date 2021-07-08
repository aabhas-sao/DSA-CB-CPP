#include <iostream>
using namespace std;

int find_last(int a[], int n, int m) {
    if(n == 0) {
        return - 1;
    }
    int ans = find_last(a, n - 1, m);

    if(a[n - 1] == m) {
        return n - 1;
    }
    return ans;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int m;
    cin>>m;
    cout<<find_last(a, n, m)<<endl;
    return 0;
}