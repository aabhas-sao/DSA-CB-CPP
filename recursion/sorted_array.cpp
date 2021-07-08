#include <iostream>
using namespace std;

bool isSorted(int a[], int n) {
    if(n == 0) {
        return true;
    }

    if(a[0] > a[1]) {
        return false;
    }

    return isSorted(a + 1, n - 1);
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    if(isSorted(a, n)) {
        cout<<"true"<<endl;
    } else {
        cout<<"false"<<endl;
    }
    return 0;
}