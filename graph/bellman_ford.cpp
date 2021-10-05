#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> bellmanFord(int V, int src, vector<vector<int>> edges) {
    vector<int> dist(V + 1, INT_MAX);
    dist[src] = 0;

    for(int i = 0; i < V - 1; i++) {
        for (auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "negative wt cycle found";
            exit(0);
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    vector<int> dist = bellmanFord(n, 1, edges);

    for (int i = 1; i < dist.size(); i++) {
        cout << "Number " << i << " is at " << dist[i] << " distance" << endl;
    }
    return 0;
}