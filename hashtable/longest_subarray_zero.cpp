#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubarraySumZero(int a[], int n) {
    unordered_map<int, int> m;
    int pre = 0;
    int ans = 0;

    for(int i = 0; i < n; i++) {
        pre += a[i];
        if(pre == 0) {
            ans = max(ans, i + 1);
        }

        if(m.find(pre) != m.end()) {
            ans = max(ans, i - m[pre]);
        } else {
            m[pre] = i;
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << longestSubarraySumZero(a, n);
    return 0;
}