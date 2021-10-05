#include <bits/stdc++.h>
using namespace std;

pair<int, int> mixtures(int a[], vector<vector<pair<int, int>>>& dp, int i, int j) {
	if (i == j) {
		return {0, a[i]};
	}

	if (dp[i][j].first != -1 && dp[i][j].second != -1) {
		return dp[i][j];
	}

	dp[i][j].first = INT_MAX;

	for (int k = i; k < j; k++) {
		auto p1 = mixtures(a, dp, i, k);
		auto p2 = mixtures(a, dp, k + 1, j);

		int smoke = p1.first + p2.first + p1.second * p2.second;
		if (smoke < dp[i][j].first) {
			dp[i][j].first = smoke;
			dp[i][j].second = (p1.second + p2.second) % 100;
		}
	}

	return dp[i][j];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];
	vector<vector<pair<int, int>>> v(n, vector < pair<int, int>>(n, make_pair(-1, -1)));
	int x;

	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
	}

	cout << mixtures(a, v, 0, n - 1).first << endl;
	return 0;
}