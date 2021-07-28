#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKArrays(vector<vector<int>> v) {
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<int> ans;

    for(int i = 0; i < v.size(); i++) {
        pq.push({v[i][0], {i, 0}});
    }

    while(!pq.empty()) {
        node element = pq.top();
        int val = element.first;
        int x = element.second.first;
        int y = element.second.second;

        pq.pop();
        ans.push_back(val);

        if(y + 1 < v[x].size()) {
            pq.push({v[x][y + 1], {x, y + 1}});
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> v = {
        {1, 2, 4, 8},
        {1, 3, 3, 9},
        {3, 5, 7}
    };

    for(auto x: mergeKArrays(v)) {
        cout << x << " ";
    }

    return 0;
}