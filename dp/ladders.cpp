#include <iostream>
using namespace std;

int laddersTopDown(int n, int k, int dp[]) {
    // base case
    if(n == 0) {
        return 1;
    }

    // lookup
    if(dp[n] != 0) {
        return dp[n];
    }

    int sum = 0;
    
    for(int i = 1; i <= k; i++) {
        if(i > n) break;
        sum += laddersTopDown(n - i, k, dp);
    }

    return dp[n] = sum;
}

int laddersBottomUpOptimized(int n, int k, int dp[]) {
    dp[0] = 1;
    // cout << dp[0] << " ";
    for (int i = 1; i <= k; i++) {
        for(int j = i - 1; j >= i - k; j--) {
            if(j < 0) break;
            dp[i] += dp[j];
        }
        // cout << dp[i] << " ";
    }
    
    for(int i = k + 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
        // cout << dp[i] << " ";
    }

    return dp[n];
}

int main() {
    int dp[100] = {0};
    // cout << laddersTopDown(6, 3, dp) << endl;
    cout << laddersBottomUpOptimized(6, 3, dp) << endl;
    return 0;
}