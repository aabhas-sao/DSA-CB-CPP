#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <cstring>
using namespace std;

template <typename T>
class Graph {
	map<T, list<T>> node;
public:
	void addEdge(T x, T y) {
		node[x].push_back(y);
	}

	void dfsHelper(T src, unordered_map<T, bool>& visited, list<T>& ordering) {
		visited[src] = true;

		for (auto x : node[src]) {
			if (!visited[x]) {
				dfsHelper(x, visited, ordering);
			}
		}

		ordering.push_front(src);
	}

	void dfs() {
		unordered_map<T, bool> visited;
		list<T> ordering;

		for (auto x : node) {
			visited[x.first] = false;
		}

		for (auto x : node) {
			if (!visited[x.first]) {
				dfsHelper(x.first, visited, ordering);
			}
		}

		for (auto x : ordering) {
			cout << x << " ";
		}
	}
};

int main() {
	Graph<string> g;
	g.addEdge("Python", "DataPreprocessing");
	g.addEdge("Python", "PyTorch");
	g.addEdge("Python", "ML");
	g.addEdge("DataPreprocessing", "ML");
	g.addEdge("ML", "DL");
	g.addEdge("DL", "FaceRecognition");
	g.addEdge("DataSet", "FaceRecognition");

	g.dfs();

	return 0;
}