#include <iostream>
#include <map>
#include <vector>
using namespace std;

void intersection(int a[], int b[], map<int, int>& s1, map<int, int>& s2) {
    vector<int> v;
    cout << "[";
    for(auto x: s2) {
        int c1 = x.second;
        int c2 = s1[x.first];
        int c3 = min(c1, c2);
        while(c3--) {
            v.push_back(x.first);
        }
    }

    for(int i = 0; i < v.size() - 1; i++) {
        cout << v[i]<<", ";
    }
    cout << v[v.size() - 1];
    cout << "]";
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    map<int, int> s1;
    map<int, int> s2;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s1[a[i]]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s2[b[i]]++;
    }
    intersection(a, b, s1, s2);
    return 0;
}