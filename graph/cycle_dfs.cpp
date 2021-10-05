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
    }

    bool cycleHelper(int node, bool* visited, bool* stack) {
        visited[node] = true;
        stack[node] = true;

        for (auto nbr: l[node]) {
            if (stack[nbr] == true) return true;
            else if(stack[nbr] == false) {
                bool cycleMila = cycleHelper(nbr, visited, stack);
                if(cycleMila) return true;
            }
        }

        // while returning remove from stack
        stack[node] = false;
        return false;
    }

    void cycle() {
        bool* visited = new bool[size];
        bool* stack = new bool[size];

        for (int i = 0; i < size; i++) {
            visited[i] = false;
            stack[i] = false;
        }

        if(cycleHelper(0, visited, stack)) {
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
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2);

    g.cycle();

    return 0;
}