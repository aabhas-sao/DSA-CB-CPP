#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	int s;
	cin >> n >> s;
	int a[n + 1];
	a[0] = 0;
	cin >> a[1];

	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}

	bool found = false;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[j] - a[i] == s) {
				found = true;
			}
			if (found) break;
		}
		if (found) break;
	}

	if (found) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}