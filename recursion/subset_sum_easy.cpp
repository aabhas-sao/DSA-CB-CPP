#include <iostream>
using namespace std;

bool subsetSum(int a[], int i, pair<int, int> sum, int n) {
    if(i >= n) {
        if(sum.first == 0  && sum.second > 0) {
            return true;
        }
        return false;
    }

    sum.first += a[i];
    sum.second++;
    bool left = subsetSum(a, i + 1, sum, n);
    sum.first -= a[i];
    sum.second--;
    bool right = subsetSum(a, i + 1, sum, n);
    
    if(left || right) {
        return true;
    }

    return false;
}

int main() {
    int t;
    cin >> t;
    int a[4];
    while (t--) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if(subsetSum(a, 0, make_pair(0, 0), n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}