#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ec(ll n, unordered_map<ll, ll>& dp) {
	if (n == 0 || n == 1) {
		return n;
	}

	if (dp.count(n) != 0) {
		return dp[n];
	}

	ll ans = 0;
	ans += ec(n / 2, dp);
	ans += ec(n / 4, dp);
	ans += ec(n / 3, dp);
	return dp[n] = max(n, ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	unordered_map<ll, ll> dp;
	cout << ec(n, dp) << endl;


	return 0;
}