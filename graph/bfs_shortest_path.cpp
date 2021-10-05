#include <bits/stdc++.h>
using namespace std;

class Graph {
	map<int, list<int>> l;
public:
	void addEdge(int u, int v) {
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void SSSP(int src, int n, vector<int>& dist) {
		vector<bool> visited(n + 1, false);
		queue<int> q;
		q.push(src);
		dist[src] = 0;
		visited[src] = true;

		while (!q.empty()) {
			int best = q.front();
			q.pop();
			for (auto nbr : l[best]) {
				if (!visited[nbr]) {
					dist[nbr] = dist[best] + 1;
					visited[nbr] = true;
					q.push(nbr);
				}
			}
		}

	}
	void clear() {
		l.clear();
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	Graph g;

	while (t--) {
		int n, m, u, v, src;
		cin >> n >> m;
		while (m--) {
			cin >> u >> v;
			g.addEdge(u, v);
		}
		cin >> src;
		vector<int> dist(n + 1, INT_MAX);

		g.SSSP(src, n, dist);

		for (int i = 1; i < n + 1; i++) {
			if (i == src) continue;
			if (dist[i] == INT_MAX) cout << "-1 ";
			else cout << dist[i] * 6 << " ";
		}
		g.clear();
		cout << endl;
	}
	return 0;
}