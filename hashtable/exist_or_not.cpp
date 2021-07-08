#include <iostream>
#include <unordered_set>
using namespace std;

bool existOrNot(int n, unordered_set<int>& s) {
    if(s.find(n) != s.end()) {
        return true;
    }
    return false;
} 

int main() {
    int t;
    cin >> t;
    int a[100000];
    while (t--) {
        unordered_set<int> s;
        int n, q;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        cin >> q;
        int p;
        while (q--) {
            cin >> p;
            if(existOrNot(p, s)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}