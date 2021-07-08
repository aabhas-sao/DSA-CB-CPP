#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return (a.second - a.first) < (b.second - b.first);
}

void display(vector<pair<int, int>> a) {
    for(auto it: a) {
        cout<<it.first<<" "<<it.second<<endl;
    }
}

void solution(vector<pair<int, int>> a) {
    sort(a.begin(), a.end(), compare);
    int last = a[0].second;
    int work = 1;
    for(int i=1; i<a.size(); i++) {
        if(a[i].first >= last) {
            work++;
        }
        last = a[i].second;
    }
    display(a);
    cout<<work<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<pair<int, int>> a;
        for(int i=0; i<n; i++) {
            int one;
            int two;
            cin>>one>>two;
            a.push_back(make_pair(one, two));
        }
        solution(a);
    }
    return 0;
}