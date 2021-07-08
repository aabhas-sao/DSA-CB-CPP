#include<iostream>
using namespace std;


void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int leastIndex = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[leastIndex]) {
                leastIndex = j;
            }
        }
        swap(a[i], a[leastIndex]);
    }
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    int b[] = {1, 3, 4, 5, 2};
    int n = sizeof(b)/ sizeof(*b);
    selection_sort(b, n);
    // int a = 4;
    // swap(b[0], a);
    display(b, n);
}