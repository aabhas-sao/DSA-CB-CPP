#include <iostream>
#include <unordered_map>
using namespace std;

int largestSubarraySumK(int a[], int n, int k) {
    int pre = 0;
    int ans = 0;
    unordered_map<int, int> m;

    for(int i = 0; i < n; i++) {
        pre += a[i];
        if(pre == k) {
            ans = max(ans, i + 1);
        }

        if(m.find(pre - k) != m.end()) {
            ans = max(ans, i - m[pre - k]);
        } else {
            m[pre] = i;
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n;
    int a[n];
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << largestSubarraySumK(a, n, k);

    return 0;
}