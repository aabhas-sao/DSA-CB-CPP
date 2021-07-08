#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cowPlaceable(int a[], int n, int c, int gap) {
    int last_cow = a[0];
    int ct = 1;
    sort(a, a+n);
    for(int i = 1; i < n; i++) {
        if(a[i] - last_cow >= gap) {
            last_cow = a[i];
            ct++;
            if(ct == c) 
                return true;
        } 
    }
    return false;
}

int minCow(int a[], int c, int n) {
    int s = 0;
    int e = a[n-1] - a[0];
    int ans = 0;
    while(s<=e) {
        int mid = (s+e)/2;
        bool cowRakhPaye = cowPlaceable(a, n, c, mid);
        if(cowRakhPaye) {
            s = mid + 1;
            ans = mid;
        }
        else {
            e = mid -1;
        }
    }
    return ans;
}

void display(vector<int> & b) {
    for(int x: b) {
        cout<<x;
    }
}

int main()  {
    int n, c;
    cin>>n>>c;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> b{1, 2, 3, 4, 5};
    display(b);
    sort(a, a+n);
    cout<<minCow(a, c, n)<<endl;    
    return 0;
}