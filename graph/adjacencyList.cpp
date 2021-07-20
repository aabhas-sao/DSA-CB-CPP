#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph {
    unordered_map<string, list<pair<string, int>>> m;
public:
    void addEdge(string x, string y, bool directed , int weight) {
        list<pair<string, int>> l;
        m[x].push_back(make_pair(y, weight));
        if(!directed) {
            m[y].push_back(make_pair(x, weight));
        }
    }

    void print() {
        for (auto city: m) {
            cout << city.first << "-> ";
            auto destinations = city.second;
            for(auto destination: destinations) {
                cout << destination.first << " " << destination.second << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge("A", "B", false, 20);
    g.addEdge("A", "D", true, 50);
    g.addEdge("A", "C", false, 10);
    g.addEdge("C", "D", false, 40);
    g.addEdge("B", "D", false, 40);

    g.print();
    return 0;
}