#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class DSU {
	ll* parent;
	ll* rank;
	int size;
public:
	DSU(ll n) {
		size = n;
		parent = new ll[n];
		rank = new ll[n];

		for (ll i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}

	}

	ll findSet(ll x) {
		if (parent[x] == x) return x;
		return parent[x] = findSet(parent[x]);
	}

	void unionSet(ll x, ll y) {
		ll s1 = findSet(x);
		ll s2 = findSet(y);
		if (s1 != s2) {
			if (rank[s1] > rank[s2]) {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			} else {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
		}
	}

	ll pairs() {
		ll ans = size * (size - 1) / 2;
		ll x = 0;

		for (ll i = 0; i < size; i++) {
			if (parent[i] == i) {
				x += rank[i] * (rank[i] - 1) / 2;
			}
		}
		return ans - x;
	}

	~DSU() {
		delete[] parent;
		delete[] rank;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, m, x, y;
	cin >> n >> m;
	DSU d(n);
	while (m--) {
		cin >> x >> y;
		d.unionSet(x, y);
	}
	cout << d.pairs() << endl;
	return 0;
}