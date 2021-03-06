#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> x,pair<int, int> y) {
    int d1 = x.first * x.first + x.second * x.second;
    int d2 = y.first * y.first + y.second * y.second;
    if(d1 == d2) {
        return x.first < y.first;
    }
    return d1 < d2;
}

int main() {
    int n;
    cin>>n;
    vector<pair<int, int>> v;
    for(int i = 0; i<n; i++) {
        int x, y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);
    for(auto it: v) {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}