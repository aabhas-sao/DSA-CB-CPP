#include <iostream>
#include "heap.h"
using namespace std;

void buildFromArray(Heap<int>& h, int a[], int n) {
    for(int i = 0; i < n; i++) {
        h.insert(a[i]);
    }
}

int main() {
    int a[] = { 4, 1, 2, 7, 3, 6, 8 };
    int n = sizeof(a) / sizeof(int);
    Heap<int> h;
    return 0;
}