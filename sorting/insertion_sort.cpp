#include<iostream>
using namespace std;


void insertion_sort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while(j >= 1 && a[j] < a[j - 1]) {
            swap(a[j], a[j-1]);
            j--;
        }
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
    insertion_sort(b, n);
    // int a = 4;
    // swap(b[0], a);
    display(b, n);
}