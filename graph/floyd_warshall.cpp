#include <bits/stdc++.h>
using namespace std;

class Graph {
	int** grid;
	int size;
public:
	Graph(int n) {
		size = n;
		grid = new int*[n];
		for (int i = 0; i < n; i++) {
			grid[i] = new int[n];
			for (int j = 0; j < n; j++) {
				if (i == j) grid[i][j] = 0;
				else grid[i][j] = INT_MAX;
			}
		}
	}

	void addEdge(int x, int y, int dist) {
		grid[x][y] = dist;
	}

	void floydWarshall() {
		for (int k = 0; k < size; k++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (grid[i][k] != INT_MAX && grid[k][j] != INT_MAX) {
						if (grid[i][k] + grid[k][j] < grid[i][j]) {
							grid[i][j] = grid[i][k] + grid[k][j];
						}
					}
				}
			}
		}
	}

	void display() {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}

	~Graph() {
		for (int i = 0; i < size; i++) {
			delete[] grid[i];
		}
		delete[] grid;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, x, y, dist;
	cin >> n >> m;
	Graph g(n);
	while (m--) {
		cin >> x >> y >> dist;
		g.addEdge(x, y, dist);
	}
	g.floydWarshall();
	g.display();

	return 0;
}