#include <iostream>
#include <list>
using namespace std;

class Graph {
    list<pair<int, int>> l;
    int s;
public:
    Graph(int size) {
        s = size;
    }

    void addEdge(int x, int y) {
        l.push_back({ x, y });
    }

    void unionSet(int x, int y, int* parent, int* weight) {
        int s1 = findSet(x, parent);
        int s2 = findSet(y, parent);
        if(s1 != s2) {
            if(weight[s1] > weight[s2]) {
                parent[s2] = s1;
                weight[s1] += weight[s2];
            } else {
                parent[s1] = s2;
                weight[s2] += weight[s1];
            }
        }
    }

    int findSet(int x, int* parent) {
        if(parent[x] == -1) return x;
        return parent[x] = findSet(parent[x], parent); // added path compression
    }

    bool containsCycle() {
        int* parent = new int[s];
        int* weight = new int[s];

        for (int i = 0; i < s; i++) {
            parent[i] = -1;
            weight[i] = 1;
        }

        for (auto node: l) {
            int a = node.first;
            int b = node.second;
            int s1 = findSet(a, parent);
            int s2 = findSet(b, parent);
            if(s1 != s2) {
                unionSet(s1, s2, parent, weight);
            } else {
                return true;
            }
        }

        for (int i = 0; i < s; i++) {
            cout << parent[i] << " ";
        }

        cout << endl;

        for (int i = 0; i < s; i++) {
            cout << weight[i] << " ";
        }

        return false;
    }

};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    if(g.containsCycle()) {
        cout << "Yes contains a cycle";
    } else {
        cout << "Nope no cycle";
    }

    return 0;
}