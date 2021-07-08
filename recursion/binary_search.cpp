#include <iostream>
using namespace std;

int binary_search(int a[], int n, int s, int e, int key) {
    //base case
    if(s > e) return -1;

    int mid = (s + e) / 2;
    if(key == a[mid]) return 1;
    if(key > a[mid]) {
        return binary_search(a, n, mid + 1, e, key);
    }
    else {
        return binary_search(a, n, s, mid - 1, key);
    }
    return -1;
}

int main() {
    int n = 6;
    int a[] = {1, 3, 5, 6, 9, 23};
    cout<<binary_search(a, n, 0, n - 1, 7);
    return 0;
}