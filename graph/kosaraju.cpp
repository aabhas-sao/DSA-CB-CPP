#include <bits/stdc++.h>
using namespace std;

void dfs(int x, bool* visited, stack<int>& s, const vector<vector<int>> graph) {
	visited[x] = true;
	for (auto nbr : graph[x]) {
		if (!visited[nbr]) {
			dfs(nbr, visited, s, graph);
		}
	}
	s.push(x);
}

void dfs2(int x, bool* visited, const vector<vector<int>> reverse_graph, vector<int>& c) {
	visited[x] = true;
	c.push_back(x);
	for (auto nbr : reverse_graph[x]) {
		if (!visited[nbr]) {
			dfs2(nbr, visited, reverse_graph, c);
		}
	}
}

void addEdge(vector<vector<int>>& graph, vector<vector<int>>& reverse_graph, int x, int y) {
	graph[x].push_back(y);
	reverse_graph[y].push_back(x);
}

void kosaraju() {

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<vector<int>> reverse_graph(n + 1, vector<int>());
	stack<int> ordering;

	graph.reserve(n + 1);
	reverse_graph.reserve(n + 1);
	int m, x, y;
	cin >> m;
	while (m--) {
		cin >> x >> y;
		addEdge(graph, reverse_graph, x, y);
	}

	bool* visited = new bool[n] {false};

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i, visited, ordering, graph);
		}
	}

	memset(visited, false, n + 1);

	while (!ordering.empty()) {
		int x = ordering.top();
		// cout << x << " " << visited[x] << endl;
		ordering.pop();
		if (visited[x]) continue;
		vector<int> c;
		dfs2(x, visited, reverse_graph, c);
		for (auto z : c) {
			cout << z << " ";
		}
		cout << endl;
	}

	return 0;
}