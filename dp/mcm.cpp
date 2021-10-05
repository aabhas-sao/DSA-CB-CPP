#include <bits/stdc++.h>
using namespace std;

int mcm(vector<int> A) {
	int dp[200][200];
	memset(dp, 0, sizeof dp);

	int n = A.size() - 1;
	int local;

	for (int i = 1; i < n; i++) {
		int c = 1;
		for (int j = i + 1; j <= n; j++) {
			local = INT_MAX;
			for (int k = c; k < j; k++) {
				local = min(local, dp[c][k] + dp[k + 1][j] + (A[c - 1] * A[k] * A[j]));
			}
			dp[c][j] = local;
			c++;
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	for (int j = 1; j <= n; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	return dp[1][n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << mcm(A) << endl;
	return 0;
}