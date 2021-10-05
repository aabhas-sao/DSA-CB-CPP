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

	void dfsHelper(T src, map<int, bool>& visited) {
		for (auto x : node[src]) {
			if (!visited[x]) {
				// cout << x << " ";
				visited[x] = true;
				dfsHelper(x, visited);
			}
		}
	}

	void dfs(T src, map<int, bool>& marked) {
		marked[src] = true;
		dfsHelper(src, marked);
	}

	int connected(T src) {
		map<int, bool> marked;

		for (auto x : node) {
			marked[x.first] = false;
		}

		int count = 0;

		for (auto it : marked) {
			if (it.second == false) {
				count++;
				dfs(it.first, marked);
			}
		}

		return count;
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
	g.addEdge(7, 8);
	g.addEdge(10, 11);
	g.addEdge(10, 12);
	cout << g.connected(0) << endl;
}