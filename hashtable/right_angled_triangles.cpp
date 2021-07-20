#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int rightTriangles(const vector<pair<int, int>> v) {
    unordered_map<int, int> x;
    unordered_map<int, int> y;
    
    int ans = 0;

    for (auto p: v) {
        x[p.first]++;
        y[p.second]++;
    }

    for(auto p: v) {
        ans += (x[p.first] - 1) * (y[p.second] - 1);
    }
    
    return ans;
}

int main() {
    vector<pair<int, int>> v;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(0, 1));
    v.push_back(make_pair(1, 1));


    cout << rightTriangles(v);

    return 0;
}