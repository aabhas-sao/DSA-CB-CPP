#include <iostream>
using namespace std;

int quick(int a[], int s, int e) {
    int i = s - 1;
    int j = s;
    int pivot = a[e];

    for(; j < e; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(int a[], int s, int e) {
    // base case if array size one or less
    if(s >= e) {
        return;
    }

    int pIndex = quick(a, s, e);
    // recursive case
    quicksort(a, s, pIndex - 1);
    quicksort(a, pIndex + 1, e);

}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    quicksort(a, 0, n - 1);
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}