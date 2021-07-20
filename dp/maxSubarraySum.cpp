#include <iostream>
#include <climits>
using namespace std;

int msas(int a[], int n) {
    int max_so_far = INT_MIN;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum < 0) {
            sum = 0;
        }
        max_so_far = max(max_so_far, sum);
    }

    return max_so_far;
}

int main() {
    int a[] = {2, 3, 0, 5, 4};
    int n = sizeof(a) / sizeof(int);
    cout << msas(a, n) << endl;
    return 0;
}