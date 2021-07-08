#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0; i<n; i++) {
            int p;
            cin>>p;
            a.push_back(p);
        }
        next_permutation(a.begin(), a.end());
        for(int i=0; i<n; i++) {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}