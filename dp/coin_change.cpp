#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int coins[] =  {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int topDownCoinChange(int n, unordered_map<int, int>& m) {
    if(n == 0 || n == 1) {
        return n;
    }
    // lookup
    if(m.find(n) != m.end()) {
        return m[n];
    }
    // recursive case
    int ans = INT_MAX;
    for(int i = 0; n <= coins[i]; i++) {
        int temp = topDownCoinChange(n - coins[i], m);
        ans = min(ans, temp);
    }
    // set value
    if(m.find(n) == m.end()) {
        m[n] = ans + 1;
    }
}

int bottomUpCoinChange(int n, int a[]) {
    a[0] = 0;
    a[1] = 1;
    for(int i = 2; i <= n; i++) {
        int ans = INT_MAX;
        for(int j = 0; coins[j] <= i; j++) {
            int temp = a[i - coins[j]];
            ans = min(temp, ans);
        }
        a[i] = ans + 1;
    }
    return a[n];
}

int main() {
    int n;
    unordered_map<int, int> m;
    int a[100];
    // cout << topDownCoinChange(111, m) << endl;
    cout << bottomUpCoinChange(8, a) << endl;
    return 0;
}