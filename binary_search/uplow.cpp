#include <iostream>
using namespace std;

int findLowerB(int *a, int n, int key) {
    int s = 0;
    int e = n - 1;

    int possIndex;
    int mid;
    while(s <= e) {
        mid = (s + e) / 2;

        if(a[mid] == key) {
            e = mid - 1;
            possIndex = mid;
        }
        else if(a[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return possIndex;
}

int findUpperB(int *a, int n, int key) {
    int s = 0;
    int e = n - 1;

    int possIndex = -1;
    int mid;
    while(s <= e) {
        mid = (s + e) / 2;

        if(a[mid] == key) {
            e = mid + 1;
            possIndex = mid;
        }
        else if(a[mid] > key) {
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
    }
    return possIndex;
}

int main() {

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int q;
    cin>>q;
    while(q--) {
        int x;
        cin>>x;
        cout<<findLowerB(a, n, x)<<" "<<findUpperB(a, n, x)<<endl;
    }

    return 0;
}