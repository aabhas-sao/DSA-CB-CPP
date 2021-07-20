#include <iostream>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// LCS - Longest Consecutive Subsequence e.g. [ 1, 2, 3, 4 ]

int lcsHashMap(int a[], int n) {
    unordered_map<int, int> m;

    int ans = INT_MIN;
    for(int i = 0; i < n; i++) {
        int num = a[i];
        if(m.count(num - 1) != 0 && m.count(num + 1) != 0) {
            int len1 = m[num - 1];
            int len2 = m[num + 1];
            int newLen = len1 + len2 + 1;
            m[num - len1] = newLen;
            m[num + len2] = newLen;

        } else if(m.count(num - 1) == 0 && m.count(num + 1) == 0) {
            m[num] = 1;

        } else if(m.count(num - 1) != 0 && m.count(num + 1) == 0) {
            int len = m[num - 1];
            m[num - len] = len + 1;
            m[num] = len + 1;

        } else {
            int len = m[num + 1];
            m[num + len] = len + 1;
            m[num] = len + 1;

        }
    }

    for(auto p: m) {
        ans = max(ans, p.second);
    }

    return ans;
}

int lcsHashSet(int a[], int n) {
    unordered_set<int> s;
    int ans = INT_MIN;

    for(int i = 0; i < n; i++) {
        s.insert(a[i]);
    }

    for(int i = 0; i < n; i++) {
        if(s.find(a[i] - 1) == s.end()) {
            int next_no = a[i] + 1;
            int streak_len = 1;
            while(s.find(next_no) != s.end()) {
                next_no++;
                streak_len++;
            }
            ans = max(ans, streak_len);
        }
    }

    return ans;
}

int main() {
    int a[] = {14, 5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
    int n = sizeof(a) / sizeof(int);

    // cout << lcsHashMap(a, n) << endl;
    cout << lcsHashSet(a, n) << endl;
    return 0;
}