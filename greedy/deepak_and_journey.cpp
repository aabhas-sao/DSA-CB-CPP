#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, t, c, d, cost;
    cin >> t;

    while(t--) {
        cin >> n;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            cin >> c >> d;
            v.push_back({c, d});
        }

        int min_station = INT_MAX;
        cost = 0;
        
        for(int i = 0; i < n; i++) {
            min_station = min(min_station, v[i].first);
            cost += min_station * v[i].second;
        }

        cout << cost << endl;
    }
}