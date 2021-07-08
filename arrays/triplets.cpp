#include <iostream>
#include <algorithm>
using namespace std;

void tripletSumn3(int a[], int n, int x) {
    sort(a, a + n);
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(a[j] + a[i] + a[k] == x) {
                    cout<<a[i]<<", "<<a[j]<<" and "<<a[k]<<endl;
                }
            }
        }
    } 
}

void dupletSum(int *a, int n, int one, int x) {
    int s = 0;
    int e = n - 1;

    while(s < e) {
        if(a[s] + a[e] == x - one) {
            cout<<one<<", "<<a[s]<<" and "<<a[e]<<endl;
            s++;
            e--;
        }
        else if(a[s] + a[e] < x - one) {
            s++;
        }
        else {
            e--;
        }
    }
}

void tripletSumn2(int a[], int n, int x) {
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        int one = a[i];
        dupletSum(a + i + 1, n - i - 1, one, x);
    }
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
    // tripletSum(a, n, x);
    tripletSumn2(a, n, x);
    return 0;
}
