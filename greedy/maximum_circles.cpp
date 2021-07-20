#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int maxCircles(vector<pair<int, int>> v) {
    int ans = 1;
    int fin = v[0].second;

    for(int i = 1; i < v.size(); i++) {
        if(v[i].first >= fin) {
            fin = v[i].second;
            ans++;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int c = n;
    vector<pair<int, int>> v;
    while(c--) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x - y, x + y));
    }
    sort(v.begin(), v.end(), compare);

    cout << n - maxCircles(v) << endl;
    return 0;
}