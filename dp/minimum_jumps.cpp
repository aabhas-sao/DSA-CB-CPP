#include <bits/stdc++.h>
using namespace std;

int mjp(int i, int n, int a[], int dp[]) {
    if (i >= n - 1) {
        return 0;
    }

    if (dp[i] != -1) return dp[i];
    int currentJump = a[i];
    int local = INT_MAX;

    for (int k = 1; k <= a[i]; k++) {
        local = min(local, mjp(i + k, n, a, dp));
    }

    if (local == INT_MAX) {
        dp[i] = INT_MAX;
        return INT_MAX;
    }

    return dp[i] = local + 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n;
    int a[1001];
    int dp[1001];

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        memset(dp, -1, sizeof dp);

        cout << mjp(0, n, a, dp) << endl;

        for (int i = 0; i <= n; i++) {
            cout << dp[i] << " ";
        }
        cout << endl;

    }

    return 0;
}