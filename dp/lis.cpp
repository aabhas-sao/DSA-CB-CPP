#include <iostream>
#include <climits>
using namespace std;

int lis(int a[] , int n, int dp[]) {
    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        dp[i] = 0;
        for(int j = 0; j < i; j++) {
            if(a[j] <= a[i]) {
                dp[i] = max(dp[i], dp[j]);
                ans = max(ans, dp[i]);
            }
        }
        dp[i]++;
    }

    return ans;
}

int lis2(int a[], int n, int dp[]) {
    dp[0] = INT_MIN;
    for(int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i] > dp[j] && a[i] < dp[j + 1]) {
                dp[j + 1] = a[i];
            }
        }
    }

    for(int i = 0; i < n + 1; i++) {
        cout << dp[i] << " ";
    }
}

int main() {
    int a[] = {1, 5, 3, 4, 9, 6, 1, 10};
    int n = sizeof(a) / sizeof(int);
    int dp[n + 1];
    // cout << lis(a, n, dp) << endl;
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }

    lis2(a, n, dp);
    return 0;
}