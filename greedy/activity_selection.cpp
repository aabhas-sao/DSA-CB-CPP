#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.second < p2.second;
}

int main() {
    int t;
    vector<pair<int, int> > v;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            int s, e;
            cin >> s >> e;
            v.push_back(make_pair(s, e));
        }

        sort(v.begin(), v.end(), compare);

        int fin = v[0].second;
        int ans = 1;

        for(int i = 1; i < v.size(); i++) {
            if(v[i].first >= fin) {
                fin = v[i].second;
                ans++;
            }
        }

        cout << ans;
        v.clear();
    }
    return 0;
}