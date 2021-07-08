#include <iostream>
using namespace std;

void merge(int a[], int s, int e) {
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = 0;

    int t[e - s + 1];

    while(i <= mid && j <= e) {
        if(a[i] < a[j]) {
            t[k++] = a[i++];
        }
        else {
            t[k++] = a[j++];
        }
    }

    while(j <= e) {
        t[k++] = a[j++];
    }
    while(i <= mid) {
        t[k++] = a[i++];

    }
    k = 0;
    for(i = s; i <= e; i++) {
        a[i] = t[k++];
    } 
}

void mergesort(int a[], int s, int e) {
    // base case
    if(s>=e) {
        return;
    }

    int mid = (s + e) / 2;

    mergesort(a, s, mid);
    mergesort(a, mid + 1, e);

    merge(a, s, e);
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    mergesort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}