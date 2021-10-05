#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class DSU {
	int* parent;
	unordered_set<int> s;
	ll size;
public:
	DSU(int n) {
		size = n;
		parent = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
		parent[0] = -1;
	}
	int findSet(int x) {
		if (parent[x] == x) return x;
		return parent[x] = findSet(parent[x]);
	}
	void unionSet(int x, int y) {
		int s1 = findSet(x);
		int s2 = findSet(y);
		if (s1 != s2) {
			parent[s1] = s2;
		}
	}
	~DSU() {
		delete[] parent;
	}

	int minRoad() {
		for (int i = 1; i <= size; i++) {
			s.insert(parent[i]);
		}
		return s.size();
	}

	ll temples(int ct) {
		ll cost = 0;

		for (int i = 0; i <= size; i++) {
			if (parent[i] == i) {
				cost += ct;
			}
		}
		return cost;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll t, n, r, ct, cr;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> n >> r >> ct >> cr;
		DSU g(n);
		ll cost = 0;
		while (r--) {
			cin >> x >> y;
			cost += cr;
			g.unionSet(x, y);
		}
		cost = min(cost, (n - g.minRoad()) * cr);
		ll costWithTemples = cost + g.temples(ct);
		cout << min(costWithTemples, ct * n) << endl;
	}
	return 0;
}