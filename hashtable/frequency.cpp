#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main() {
    int n;
    int a[n];
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        m[a[i]]++;
    }
    int val;
    int ans = INT_MIN;
    for(auto x: m) {
        if(x.second > ans) {
            val = x.first;
        }
    }
    cout << val << endl;
    return 0;
}