#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int knapsack(int n, vector<int> prices, vector<int> wts, int wt, vector<vector<int>>& dp) {
    // base case ( if all items have been selected or capcity is full)
    if (n == 0 || wt == 0) {
        return 0;
    }

    if (dp[n - 1][wt - 1] != -1) {
        return dp[n - 1][wt - 1];
    }

    int inc = 0, exc = 0;
    if (wts[n - 1] <= wt) {
        inc = prices[n - 1] + knapsack(n - 1, prices, wts, wt - wts[n - 1], dp);
    }

    exc = knapsack(n - 1, prices, wts, wt, dp);

    return dp[n - 1][wt - 1] = max(inc, exc);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, capacity;
    cin >> n >> capacity;
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    int x;

    vector<int> wts;
    for (int i = 0; i < n; i++) {
        cin >> x;
        wts.push_back(x);
    }
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        cin >> x;
        prices.push_back(x);
    }

    cout << knapsack(n, prices, wts, capacity, dp) << endl;

    for (auto x : dp) {
        for (auto z : x) {
            cout << z << " ";
        }
        cout << endl;
    }

    return 0;
}