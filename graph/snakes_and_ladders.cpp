#include <bits/stdc++.h>
using namespace std;

class Graph {
	map<int, list<int>> l;
public:
	void addEdge(int x, int y) {
		l[x].push_back(y);
	}

	void constructGraph(int n, unordered_map<int, int> u) {
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int dice = 1; dice <= 6; dice++) {
				if (i + dice > n) break;
				temp = dice + i;
				temp += u[temp];
				addEdge(i, temp);
			}
		}
	}

	int bfs(int n) {
		queue<int> q;
		vector<bool> visited(n + 1, false);
		vector<int> steps(n + 1, INT_MAX);
		q.push(0);
		steps[0] = 0;
		visited[0] = true;

		while (!q.empty()) {
			auto pos = q.front();
			q.pop();
			for (auto nbr : l[pos]) {
				if (!visited[nbr]) {
					q.push(nbr);
					steps[nbr] = steps[pos] + 1;
					visited[nbr] = true;
				}
			}
		}

		return steps[n];
	}

	void display() {
		for (auto x : l) {
			cout << x.first << ": ";
			for (auto z : x.second) {
				cout << z << " ";
			}
			cout << endl;
		}
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
		int n, l, s, x, y;
		unordered_map<int, int> u;
		cin >> n >> l >> s;
		Graph g;
		while (l--) {
			cin >> x >> y;
			u[x] = y - x;
		}
		while (s--) {
			cin >> x >> y;
			u[x] = y - x;
		}

		g.addEdge(n, n);

		// for (auto x : u) {
		// 	cout << x.first << " " << x.second << endl;
		// }

		g.constructGraph(n, u);
		cout << g.bfs(n) << endl;
		// g.display();
	}
	return 0;
}