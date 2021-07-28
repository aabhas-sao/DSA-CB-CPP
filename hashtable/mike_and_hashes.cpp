#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> u;

bool compare(int a, int b) {
    return u[a] < u[b];
}

int main() {
    int n;
    cin >> n;
    int a[n]; 

    vector<int> v;
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(u.count(a[i]) == 0) v.push_back(a[i]);    
        u[a[i]] = count++;
    }

    sort(v.begin(), v.end(), compare);
    for (auto x: v) {
        cout << x << endl;
    }

    return 0;
}