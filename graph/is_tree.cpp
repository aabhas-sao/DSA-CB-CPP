#include <iostream>
#include <list>
#include <queue>
using namespace std;

template <typename T>
class Graph {
	list<T> *l;
	int size;
public:
	Graph(int V) {
		l = new list<T>[V];
		size = V;
	}

	void addEdge(T x, T y) {
		l[x].push_back(y);
	}

	bool isTree(int src) {
		queue<int> q;
		int* visited = new int[size];
		int* parent = new int[size];

		for (int i = 0; i < size; i++) {
			visited[i] = false;
			parent[i] = i;
		}

		q.push(src);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (auto nbr : l[x]) {
				if (visited[nbr] && parent[nbr] != x) {
					return false;
				} else if (!visited[nbr]) {
					visited[nbr] = true;
					parent[nbr] = x;
					q.push(nbr);
				}
			}
		}

		return true;
	}
};

int main() {
	Graph<int> g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 3);

	if (g.isTree(0)) {
		cout << "yes it's a treee";
	} else {
		cout << "not a tree";
	}

	return 0;
}