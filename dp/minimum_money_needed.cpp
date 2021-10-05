#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mmn(int w, int dp[], int prices[], int n) {
	if (w == 0) {
		return 0;
	}

	if (dp[w] != -1) return dp[w];

	int local = INT_MAX;

	for (int i = 1; i <= w; i++) {
		if (w - i >= 0 && prices[i] != -1) {
			if (mmn(w - i, dp, prices, n) != INT_MAX) {
				local = min(local, prices[i] + mmn(w - i, dp, prices, n));
			}
		}
	}


	return dp[w] = local;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, w;
	cin >> n >> w;
	int prices[n + 1];
	int dp[n + 1];

	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= n; i++) {
		cin >> prices[i];
	}
	int ans = mmn(w, dp, prices, n);
	if ( ans == INT_MAX) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}

	return 0;
}