#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    if(b.second != a.second) { 
        return a.second < b.second;
    }
    int i = 0;
    int j = 0;
    while(i < a.first.length() && j < b.first.length()) {
        if(a.first[i] != b.first[j]) {
            return a.first[i] < b.first[j];
        }
        i++, j++;
    }
    return a.first.length() < b.first.length();
}

void display(vector<pair<string, int>>& v) {
    for(int i = 0; i < v.size(); i++) {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
}

int main() {
    int x;
    int n;
    cin>>x;
    cin>>n;
    vector<pair<string, int>> v;
    for(int i = 0; i < n; i++) {
        string s;
        cout<<s;
        int p;
        cin>>s>>p;
        pair<string, int> q = make_pair(s, p);
        if(q.second >= x) {
            v.push_back(q);
        }
    }

    sort(v.begin(), v.end(), compare);
    display(v);
    return 0;
}