#include <bits/stdc++.h>
using namespace std;

class Graph {
	list<pair<int, int>> *l;
	int v;
public:
	Graph(int n) {
		l = new list<pair<int, int>>[n + 1];
		v = n;
	}

	void addEdge(int x, int y, int wt) {
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	int dfsHelper(int node, bool* visited, int* count , int& ans) {
		count[node] = 1;
		visited[node] = true;

		for (auto nbr : l[node]) {
			if (!visited[nbr.first]) {
				count[node] += dfsHelper(nbr.first, visited, count, ans);
				ans += min(count[nbr.first], v - count[nbr.first]) * 2 * nbr.second;
			}
		}
		return count[node];
	}

	void dfs() {
		bool* visited = new bool[v + 1] {false};

		int* count = new int[v + 1] {0};

		int ans = 0;
		dfsHelper(1, visited, count, ans);

		cout << ans << endl;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t, n, u, v, w;
	cin >> t;
	while (t--) {
		cin >> n;
		Graph g(n);

		n--;
		while (n--) {
			cin >> u >> v >> w;
			g.addEdge(u, v, w);
		}

		g.dfs();
	}
	return 0;
}