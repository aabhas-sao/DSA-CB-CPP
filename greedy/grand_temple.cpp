#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int grandTemple(vector<int>& x, vector<int>& y) {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int max_x = INT_MIN;
    int max_y = INT_MIN;

    for(int i = 0; i < x.size() - 1; i++) {
        int len_x = x[i + 1] - x[i] - 1;
        int len_y = y[i + 1] - y[i] - 1;
        max_x = max(max_x, len_x);
        max_y = max(max_y, len_y);
    }

    return max_x * max_y;
}


int main() {
    int n;
    cin >> n;
    vector<int> x;
    vector<int> y;
    // int max_x = INT_MIN;
    // int max_y = INT_MIN;
    while(n--) {
        int p, q;
        cin >> p >> q;
        x.push_back(p);
        y.push_back(q);
        // max_x = max(p, max_x);
        // max_y = max(q, max_y);
    }

    cout << grandTemple(x, y) << endl;
}