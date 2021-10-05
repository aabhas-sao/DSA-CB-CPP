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

	void topologicalSort() {
		int* indegree = new int[size];
		queue<int> q;

		for (int i = 0; i < size; i++) {
			indegree[i] = 0;
		}

		for (int i = 0; i < size; i++) {
			for (auto it : l[i]) {
				indegree[it]++;
			}
		}


		for (int i = 0; i < size; i++) {
			if (indegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int x = q.front();
			q.pop();
			cout << x << " ";
			for (auto it : l[x]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
	}
};

int main() {
	Graph<int> g(6);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(3, 5);
	g.addEdge(4, 5);

	g.topologicalSort();
	return 0;
}