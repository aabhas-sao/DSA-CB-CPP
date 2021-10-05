#include <iostream>
#include <list>
using namespace std;

class Graph {
    list<int>* l;
    int size;
public:
    Graph(int s) {
        l = new list<int>[s];
        size = s;
    }
    void addEdge(int x, int y) {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycleHelper(int node, bool* visited, int parent) {
        visited[node] = true;

        for (auto nbr: l[node]) {
            if (!visited[nbr]) {
                bool cycleMila = cycleHelper(nbr, visited, node);
                if (cycleMila) return true;
            }
            else if (nbr != parent) return true;
        }

        return false;
    }

    void cycle() {
        bool* visited = new bool[size];

        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }

        if(cycleHelper(0, visited, -1)) {
            cout << "Yes, cycle is present";
        } else {
            cout << "No cycle present";
        }
    
    }
};


int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.cycle();

    return 0;
}