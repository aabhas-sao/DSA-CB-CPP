#include <iostream>
#include <queue>
using namespace std;

#define ll long long int 

int main() {
    int n;
    int k;
    cin >> n >> k;
    priority_queue<ll> pq;
    while(n--) {
        int q;
        cin >> q;

        if (q == 1) {
            int x, y;
            cin >> x >> y;
            ll distance = x * x + y * y;

            pq.push(distance);

            while(pq.size() != k) {
                pq.pop();
            }
        } else {
            cout << pq.top() << endl;
        }
    }
    return 0;
}