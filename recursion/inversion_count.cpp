#include <iostream>
using namespace std;

int merge(int a[], int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = 0;

    int count = 0;

    int t[e - s + 1];
    while(i <= mid && j <= e) {
        if(a[i] > a[j]) {
            count += mid - i + 1;
            t[k++] = a[j++];
        }
        else {
            t[k++] = a[i++];
        }
    }
    while(i <= mid) {
        t[k++] = a[i++];
    }
    while(j <= e) {
        t[k++] = a[j++];
    }

    k = 0;
    for(i = s; i <= e; i++) {
        a[i] = t[k++];
    }
    return count;
}

int inversionCount(int a[], int s, int e) {
    // base case
    if(s>=e) {
        return 0;
    }
    int mid = (s + e) / 2;
    int x = inversionCount(a, s, mid);
    int y = inversionCount(a, mid + 1, e);
    int z = merge(a, s, e);

    return x + y +z;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    cout<<inversionCount(a, 0, n - 1)<<endl;
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}