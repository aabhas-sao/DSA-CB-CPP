#include <bits/stdc++.h>
using namespace std;

class DSU {
	int* parent;
	int* rank;
	int size;
public:
	DSU(int n) {
		parent = new int[n];
		rank = new int[n];
		size = n;

		for (int i = 0; i < n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	void clear() {
		for (int i = 0; i < size; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int findSet(int x) {
		if (parent[x] == x) {
			return x;
		}
		return parent[x] = findSet(parent[x]);
	}

	void unionSet(int x, int y) {
		int s1 = findSet(x);
		int s2 = findSet(y);

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

};

int kruskal(priority_queue < pair<int, pair<int, int>>,
            vector< pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
            > pq
            , DSU dsu) {
	int cost = 0;

	while (!pq.empty()) {
		auto nodePairs = pq.top();
		pq.pop();

		int from = nodePairs.second.first;
		int to = nodePairs.second.second;


		if (dsu.findSet(from) != dsu.findSet(to)) {
			cost += nodePairs.first;
			dsu.unionSet(from, to);
		}
	}

	return cost;
}

int prim(int src, int n) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> active_edges;
	bool visited[n + 1] {false};
	int cost = 0;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			for (auto nbr : l[i]) {
				if (!visited[nbr.second]) {
					pq.push({nbr.first, {i, nbr.second}});
				}
			}
		}
	}

	memset(visited, 0, sizeof visited);

	while (!pq.empty()) {
		int nbrPair = pq.top();
		pq.pop();
		int from = nbrPair.second.first;
		int to = nbrPair.second.second;
		visited[from] = true;

		if (!visited[to]) {
			cost += nbrPair.first;
		}
	}

	return cost;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	priority_queue < pair<int, pair<int, int>>,
	               vector< pair<int, pair<int, int>>>,
	               greater<pair<int, pair<int, int>>>
	               > pq;


	vector<vector<pair<int, int>>> l(n + 1, vector<pair<int, int>>());

	int m, x, y, wt;
	cin >> m;
	while (m--) {
		cin >> x >> y >> wt;
		pq.push({wt, {x, y}});
		l[x].push_back({wt, y});
		l[y].push_back({wt, x});
	}


	// Logic
	DSU dsu(n + 1);

	cout << kruskal(pq, dsu) << endl;


	// prim
	dsu.clear();

	bool* visited = new bool[n + 1] {false};
	int* cost = new int {0};

	for (int i = 1; i < l.size(); i++) {
		cout << "Node " << i << ": ";
		for (auto x : l[i]) {
			cout << x.first << " " << x.second << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < l.size(); i++) {
		sort(l[i].begin(), l[i].end());
	}

	prim(l, 1, visited, cost, dsu);

	cout << *cost << endl;

	return 0;
}