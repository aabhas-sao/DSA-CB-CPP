#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph {
	map<T, list<T>> node;
	map<int, int> dist;
public:
	void addEdge(T x, T y) {
		node[x].push_back(y);
	}

	void constructGraph(int grid[], int n) {
		for (int i = 0; i <= n; i++) {
			for (int dice = 1; dice <= 6; dice++) {
				int j = i + dice + grid[i + dice];

				if (j <= 36) {
					addEdge(i, j);
				}
			}
		}
		addEdge(n, n);
	}

	void bfs(T src) {
		// set inital shortest distance of all nodes to infinity
		for (int i = 0; i < 50; i++) {
			dist[i] = INT_MAX;
		}

		queue<T> q;
		q.push(src);
		dist[src] = 0;

		while (!q.empty()) {
			T temp = q.front();
			q.pop();
			for (T x : node[temp]) {
				if (dist[x] == INT_MAX) {
					q.push(x);
					dist[x] = dist[temp] + 1;
				}
			}

		}

		for (auto x : dist) {
			cout << x.first << " " << x.second << endl;
		}
	}

	void display() {
		for (auto x : node) {
			cout << "Node " << x.first << " ";
			for (auto y : x.second) {
				cout << y << " ";
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
	int x;
	int grid[50] = {0};
	grid[2] = 13;
	grid[5] = 2;
	grid[9] = 18;
	grid[18] = 11;
	grid[17] = -13;
	grid[20] = -14;
	grid[24] = -8;
	grid[25] = 10;
	grid[32] = -2;
	grid[34] = -22;

	Graph<int> g;
	g.constructGraph(grid, 36);
	g.display();
	g.bfs(0);
}
