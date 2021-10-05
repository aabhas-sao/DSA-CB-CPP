#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
using namespace std;

template <typename T>
class Graph {
	map<T, list<T>> node;
public:
	void addEdge(T x, T y) {
		node[x].push_back(y);
		node[y].push_back(x);
	}

	void dfsHelper(T src, unordered_map<int, bool>& visited) {
		visited[x] = true;

		for (auto x : node[src]) {
			if (!visited[x]) {
				cout << x << " ";
				dfsHelper(x, visited);
			}
		}
	}

	void dfs(T src) {
		unordered_map<int, bool> visited;
		visited[src] = true;
		dfsHelper(src, visited);
	}
};

int main() {
	Graph<int> g;
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(4, 5);

	g.dfs(0);
}