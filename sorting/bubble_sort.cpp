#include<iostream>
using namespace std;


void bubble_sort(int a[], int n) {
    int comp = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                swap(a[i], a[j]);
                comp++;
            }
        }
    }
    cout<<comp<<endl;
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        a[i] = n - i;
    }
    bubble_sort(a, n);
    display(a, n);
}