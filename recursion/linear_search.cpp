#include <iostream>
using namespace std;

int lastOcc(int *a, int n, int key) {
    // base case
    if(n == 0) {
        return -1;
    }

    // recursive case
    int lastIndex = lastOcc(a + 1, n - 1, key);
    if(lastIndex == -1) {
        if(a[0] == -1) {
            return 0;
        }
        else {
            return -1;
        }
    }
    return lastIndex + 1;
}

int firstOcc(int *a, int n, int key) {
    if(n == 0) {
        return -1;
    }
    if(a[0] == key) {
        return 0;
    }
    int i = firstOcc(a + 1, n - 1, key);
    if(i == -1) {
        return -1;
    } else {
        return i + 1;
    }
}

int main() {
    int a[] = {1, 2, 4, 5, 6, 7, 8};
    int n = sizeof(a)/ sizeof(int);
    cout<<*(a+1)<<endl;
    cout<<lin_search_rec(a, 0, n, 2);
    return 0;
}