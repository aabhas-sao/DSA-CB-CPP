#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>
class Graph {
    map<T, list<T>> m;
public:
    void addEdge(int x, int y) {
        m[x].push_back(y);
        m[y].push_back(x);
    }

    void bfs(T src) {
        queue<T> q;
        unordered_map<T, bool> visited;
        q.push(src);

        visited[src] = true;

        while(!q.empty()) {
            T x = q.front();
            q.pop();
            
            for (auto it: m[x]) {
                if(!visited[it]) {
                    cout << it << " ";
                    q.push(it);
                    visited[it] = true;
                }
            } 

        }
    }

};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    g.bfs(0);

    return 0;
}