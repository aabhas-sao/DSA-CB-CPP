#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t, n, k;
    int a[100000];
    cin >> t;

    while (t--) {
        cin >> n >> k;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> u;


        int times;
        vector<int> v(k, -1);


        for (int i = 0; i < n; i++) {
            times = k;
            cin >> a[i];
            if (pq.size() == k) {
                pq.pop();
            }

            u[a[i]]++;
            pq.push({u[a[i]], a[i]});

            int freqTop;

            while (!pq.empty() && times--) {
                cout << pq.top().second << " ";
                pq.pop();
                freqTop = pq.top().first;
                while (!pq.empty() && pq.top().first == freqTop && times--) {
                    v.push_back(pq.top().second);
                }
                for (auto x : v) {
                    if (x != -1) {
                        cout << x << " ";
                    }
                }
                v.clear();
            }
        }
    }
}