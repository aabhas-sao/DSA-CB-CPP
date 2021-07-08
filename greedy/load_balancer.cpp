#include <iostream>
#include <climits>
using namespace std;

int load_balancer(int a[], int n) {
    int sum = a[0];
    int ans = INT_MIN;
    for (int i = 1; i < n; i++) {
        a[i] += sum;
        sum = a[i];
    }
    if(sum % n != 0) return -1;
    int desiredNum = sum / n;
    cout <<desiredNum <<endl;
    for(int i = 0; i < n; i++) {
        int req = (i + 1) * desiredNum;
        int localAns = abs(req - a[i]);
        ans = max(localAns, ans);
    }
    return ans;
}

int main() {
    // int n;
    int n = 4;
    int a[n] = {5, 2, 2, 3};
    // cin >> n;
    // int a[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    cout << load_balancer(a, n);
    return 0;
}