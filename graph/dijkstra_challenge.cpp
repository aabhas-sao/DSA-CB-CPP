#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Graph {
	map<int, list<pair<int, int>>> l;
public:
	void addEdge(int x, int y, int wt) {
		l[x].push_back({y, wt});
		l[y].push_back({x, wt});
	}

	vector<int> dijkstra(int src) {
		int size = l.size() + 1;
		vector<int> dist(size, INT_MAX);
		set<pair<int, int>> s;

		dist[src] = 0;
		s.insert({dist[src], src});

		while (!s.empty()) {
			auto nodePair = *(s.begin());
			s.erase(s.begin());
			int node = nodePair.second;

			for (auto nbr : l[node]) {
				int dest = nbr.first;
				if (dist[node] != INT_MAX && dist[node] + nbr.second < dist[dest]) {
					auto f = make_pair(dist[dest], dest);
					if (s.find(f) != s.end()) {
						s.erase(f);
					}

					dist[dest] = dist[node] + nbr.second;
					s.insert({dist[dest], dest});
				}
			}
		}

		return dist;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--) {
		int n, m, src;
		Graph g;
		cin >> n >> m;
		while (m--) {
			int x, y, wt;
			cin >> x >> y >> wt;
			g.addEdge(x, y, wt);
		}
		cin >> src;
		vector<int> dist = g.dijkstra(src);

		for (int i = 1; i <= n; i++) {
			if (i == src) continue;
			if (dist[i] == INT_MAX) {
				cout << "-1 ";
			}
			else {
				cout << dist[i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}