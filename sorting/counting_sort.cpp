#include<iostream>
#include<climits>
using namespace std;

void counting_sort(int a[], int n) {
    int largest = INT_MIN;
    for(int i = 0; i < n; i++) {
        largest = max(largest, a[i]);
    }

    int * freq = new int[largest + 1]{0};
    for(int i=0; i < n; i++) {
        freq[a[i]]++;
    }
    for(int i = 0; i < largest + 1; i++) {
        while(freq[i]--) {
            cout<<i<<" ";
		}
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    counting_sort(a, n);
}