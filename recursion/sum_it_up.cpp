#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool sumItUp(int a[], int n, int t, int i, vector<int>& v, set<vector<int>>& s) {
    // base case
    if (t == 0) {
       s.insert(v);
        return true;
    }

    for(int k = i; k < n; k++) {
        v.push_back(a[k]);
        if(t - a[k] < 0) break;
        sumItUp(a, n, t - a[k], k + 1, v, s);
        v.pop_back();
    }
    v.pop_back();
    return true;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int t;
    cin >> t;

    sort(a, a + n);
	vector<int> v;
    set<vector<int>> s;
	sumItUp(a, n, t, 0, v, s);
    for(auto x: s) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}