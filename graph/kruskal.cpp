#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
    int* parent;
    int* weight;
    int s;

public:
    DSU(int size) {
        s = size;
        parent = new int[s];
        weight = new int[s];

        for (int i = 0; i < s; i++) {
            parent[i] = -1;
            weight[i] = 1;
        }
    }

    int findSet(int x) {
        if(parent[x] == -1) {
            return x;
        }

        return parent[x] = findSet(parent[x]);
    }

    void unionSet(int a, int b) {
        int s1 = findSet(a);
        int s2 = findSet(b);
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
};

class Graph {
    vector<vector<int>> edgelist;
    int s;
public:
    Graph(int size) {
        s = size;
    }
    void addEdge(int a, int b, int w) {
        edgelist.push_back({w, a, b});
    }

    int kruskal() {
        DSU dsu(s);
        sort(edgelist.begin(), edgelist.end());
        int cost = 0;
        
        for (auto edge: edgelist) {
            int w = edge[0];
            int a = edge[1];
            int b = edge[2];
            if(dsu.findSet(a) != dsu.findSet(b)) {
                cost += w;
                dsu.unionSet(a, b);
            }
        }
        return cost;
    }
};



int main() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 0, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 2, 2);
    cout << g.kruskal() << endl;
    return 0;
}