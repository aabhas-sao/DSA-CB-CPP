#include <bits/stdc++.h>
using namespace std;

int optimal(int a[], int i, int j) {
	if (i > j) {
		return 0;
	}
	int ans = 0;
	ans += max(
	         min(optimal(a, i + 2, j), optimal(a, i + 1, j - 1)) + a[i]
	         , min(optimal(a, i + 1, j - 1), optimal(a, i, j - 2)) + a[j]
	       );

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	int a[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << optimal(a, 0, n - 1) << endl;
	return 0;
}