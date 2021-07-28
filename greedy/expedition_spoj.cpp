#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first > p2.first;
}

int main() {
    int t, n, d, f, D, F, prev = 0, x = 0, ans = 0;
    bool flag = false;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<pair<int, int>> v;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            cin >> d >> f;
            v.push_back(make_pair(d, f));
        }

        sort(v.begin(), v.end(), compare);

        cin >> D >> F;

        for(int i = 0; i < n; i++) {
            v[i].first = D - v[i].first;
        }

        // Begin Logic here
        prev = 0; x = 0; ans = 0;
        flag = false;

        while (x < n) {
            // next town is reachable
            if (F >= v[x].first - prev) {
                F = F - (v[x].first - prev);

                // push unused fuel station to priority queue
                pq.push(v[x].second);
                prev = v[x].first;
            } else {
                // recharger fuel
                if(pq.empty()) {
                    flag = true;
                    break;
                }
                F += pq.top();
                pq.pop();
                ans++;
                continue;
            }
            x++;
        }

        if(flag) {
            cout << -1 << endl;
            continue;
        }

        D = D - v[n - 1].first;
        if(F >= D) {
            cout << ans << endl;
            continue;
        }

        while(F < D) {
            if(pq.empty()) {
                flag = 1;
                break;
            }
            F += pq.top();
            ans++;
            pq.pop();
        }

        if(flag) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }

    }
    return 0;
}