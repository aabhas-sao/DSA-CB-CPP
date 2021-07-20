#include <iostream>
using namespace std;

int pivot(int a[], int n) {
    int s = 0;
    int e = n - 1;

    while(s <= e) {
        int mid = (s + e) / 2;
        if(s == e || s + 1 == e) {
            if(s + 1 == e) {
                return s + 1;
            }
            return s;
        }
        if(a[mid] >= a[s]) {
            s = mid;
        } else {
            e = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << pivot(a, n) << endl;

    return 0;
}