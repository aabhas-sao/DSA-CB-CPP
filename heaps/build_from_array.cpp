#include <iostream>
#include "heap.h"
using namespace std;

void buildFromArray(int a[], int n) {
    for(int i = 1; i < n; i++) {
        int idx = i;
        int parent = idx / 2;

        while(idx > 1 && a[idx] < a[parent]) {
            swap(a[idx], a[parent]);
            idx = parent;
            parent /= 2;
        }
    }
}

void heapify(int a[], int id, int n) {
    int parent = id / 2;
    int last = n - 1;

    int left = id * 2;
    int right = left + 1;

    int min = id;

    if(left <= last && a[left] < a[id]) {
        swap(a[left], a[id]);
        min = left;
    }

    if(right <= last && a[right] < a[left]) {
        swap(a[right], a[left]);
        min = right;
    }

    if(min != id) {
        heapify(a, min, n);
    }
}

void buildHeapOptimized(int a[], int n) {
    int idx = n / 2 - 1;

    for(int i = idx; i > 0; i--) {
        
        
    }
}

int main() {
    int a[] = { -1, 4, 1, 2, 7, 3, 6, 8 };
    int n = sizeof(a) / sizeof(int);
    
    buildFromArray(a, n);

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}