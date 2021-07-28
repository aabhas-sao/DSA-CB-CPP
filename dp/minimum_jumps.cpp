#include <iostream>
#include <climits>
using namespace std;


int minJumps(int a[], int n, int i, int dp[]) {
    if(i >= n) {
        return 0;
    }

    if(a[i] == 0) {
        return INT_MAX;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    int local = INT_MAX;

    
    for (int j = 1; j <= a[i]; j++) {
        int res = minJumps(a, n, i + j, dp);
        if(res == INT_MAX) continue;
        local = min(res, local);
    }

    if(local == INT_MAX) return INT_MAX;

    return dp[i] = local + 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int dp[n];

        for (int i = 0; i < n; i++) {
            dp[i] = -1;
        }

        cout << minJumps(a, n, 0, dp) << endl;
    }

    return 0;
}