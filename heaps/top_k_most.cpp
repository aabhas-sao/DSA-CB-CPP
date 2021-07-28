#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> node;

class NodeCompare {
    bool operator()(node n1, node n2) {
        // if(n1.second != n2.second) {
        //     return n1.second < n2.second;
        // }
        return n1.first < n2.first;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        priority_queue<node, vector<node>, NodeCompare> pq;

        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            pq.push({x, 0});
        }

        while (!pq.empty()) {
            cout << pq.top().first << endl;
            pq.pop();
        }
    }
    return 0;
}