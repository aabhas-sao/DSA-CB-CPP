#include <iostream>
#include <climits>
#include <vector>
using namespace std;

typedef pair<int, int> node;

int knapsack(node items[], int n, int i, int capacity, vector<vector<int>>& dp) {
    // base cases
    if (i == n) {
        return 0;
    }

    // if already in dp array
    if(dp[capacity][i] != -1) {
        return dp[capacity][i];
    }

    cout << dp[capacity][i] << endl;

    if(capacity - items[i].first >= 0) {
        dp[capacity - items[i].first][i + 1] = knapsack(items, n, i + 1, capacity - items[i].first, dp);
        int op1 = items[i].second + dp[capacity - items[i].first][i + 1];
        dp[capacity][i + 1] = knapsack(items, n, i + 1, capacity, dp);
        
        return max(op1, dp[capacity][i + 1]);
    }

    return dp[capacity][i + 1] = knapsack(items, n, i + 1, capacity, dp);
}

int main() {
    int n, k;
    cin >> n >> k;

    node items[n];

    vector<vector<int>> dp(k, vector<int>(n, -1));

    for(int i = 0; i < n; i++) {
        cin >> items[i].first;
    }

    for(int i = 0; i < n; i++) {
        cin >> items[i].second;
    }

    knapsack(items, n, 0, k, dp);

    for (auto x: dp) {
        for (auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}