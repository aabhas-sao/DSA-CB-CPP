#include <iostream>
using namespace std;

int bs(int a[], int n, int key) {
    int s = 0;
    int e = n - 1;
    int mid;
    while(s <= e) {
        mid = (s + e) / 2;
        if(a[mid] == key) {
            return mid; 
        }
        else if(a[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int x;
    cin>>x;

    cout<<bs(a, n, x)<<endl;
    return 0;
}