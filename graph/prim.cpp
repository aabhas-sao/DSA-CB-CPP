#include <iostream>
#include <map>
#include <list>
#include <algorithm>
#include <queue>
using namespace std;

class Graph {
    map<int, list<pair<int, int>>> l;
    int size;
public:
    Graph(int s) {
        size = s;
    }

    void addEdge(int x, int y, int w) {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prim() {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        bool* visited = new bool[size];

        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
        q.push({0, 0});
        int cost = 0;
        while(!q.empty()) {
            auto best = q.top();
            q.pop();
            int to = best.second;
            if(visited[to]) {
                continue;
            }
            int weight = best.first;
            cost += weight;
            visited[to] = true;

            for (auto node: l[to]) {
                if(visited[node.first] == false) {
                    q.push({node.second, node.first});
                }
            }
        }

        return cost;
    }
    void display() {
        for(auto node: l) {
            cout << "Node " << node.first <<"  "; 
            for (auto it : node.second) {
                cout << it.first << " " << it.second << " XXX ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 2);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 3);
    g.addEdge(1, 2, 2);
    cout << g.prim();
    return 0;
}