#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort_recursive(int a[], int j, int n) {
    // base case outer loop
    if(n == 0) {
        return;
    }

    // inner loop reaches last element and go for next outer iteration
    if(j == n - 1) {
        return bubble_sort_recursive(a, 0, n - 1);
    }

    // if j + 1th element is smaller than jth el swap them
    if(a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
    }

    // next iteration of inner loop
    return bubble_sort_recursive(a, j + 1, n);
}



void bbs(int a[], int n) {
    static int count = 0;
    // base case for termination of inner loop
    if(n == 0) {
        return;
    }
    count++;
    bbs(a + 1, n - 1);
    if(a[0] > a[1]) {
        swap(a[0], a[1]);
    }
    bbs(a + 1, n - 1);
    cout<<count<<endl;
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i = 0; i < n; i++) {
    //     cin>>a[i];
    // }
    
    // bubble_sort_recursive(a, 0, n);
    // display(a, n);

    int a[] = {3, 4, 1, 5, 2, 6};
    int n = 6;
    bbs(a, n);
    cout<<endl;
    display(a, n);
    return 0;
}