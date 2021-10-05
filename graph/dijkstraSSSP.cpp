#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <set>
#include <cstring>
using namespace std;

template <typename T>
class Graph {
    map<T, list<pair<T, int>>> m;
public:
    void addEdge(T x, T y, int dist, bool undirected = true) {
        m[x].push_back({ y, dist });
        if(undirected) {
            m[y].push_back({ x, dist });
        }
    }

    void dijkstrasSSSP(T src) {
       map<T, int> dist;
        set<pair<int, T>> s;
        
        for (auto elem: m) {
            dist[elem.first] = INT_MAX;
        }

        dist[src] = 0;
        s.insert({dist[src], src});

        while (!s.empty()) {
            auto nodePair = *(s.begin());
            s.erase(s.begin());
            T node = nodePair.second;

            for (auto childPair: m[node]) {
                if (dist[node] + childPair.second < dist[childPair.first]) {
                    T dest = childPair.first;
                    auto f = s.find({dist[dest], dest});
                    
                    if(f != s.end()) {
                        s.erase(f);
                    }

                    dist[dest] = dist[node] + childPair.second;
                    s.insert({dist[dest], dest});
                }
            }
        }

        for (auto x: dist) {
            cout << x.first << " is at a distance of " << x.second << endl;
        }

    }
};


int main() {
    /*
    Graph<int> g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 2);
    g.addEdge(1, 4, 7);

    g.dijkstrasSSSP(1);
    */

    Graph<string> India;
    India.addEdge("Amritsar", "Delhi", 1);
    India.addEdge("Amritsar", "Jaipur", 4);
    India.addEdge("Jaipur", "Delhi", 2);
    India.addEdge("Jaipur", "Mumbai", 8);
    India.addEdge("Bhopal", "Agra", 2);
    India.addEdge("Mumbai", "Bhopal", 3);
    India.addEdge("Agra", "Delhi", 1);

    India.dijkstrasSSSP("Amritsar");

    return 0;
}