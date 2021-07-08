#include <iostream>
#include <climits>
using namespace std;

bool isPossible(int a[], int n, int m, int total_pages) {
    int studentsUsed = 1;
    int page = 0;
    for(int i = 0; i < n; i++) {
        if(page + a[i] > total_pages) {
            page = a[i];
            studentsUsed++;
            if(studentsUsed > m) {
                return false;
            }
        }
        else {
            page += a[i];
        }
    }
    return true;
}

int findMinPages(int a[], int n, int m) {
    if(n < m) {
        return -1;
    }
    int s = a[n-1];
    int e = 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        e += a[i];
    }

    while(s <= e) {
        int mid = (s + e) / 2;
        if(isPossible(a, n, m, mid)) {
            e = mid - 1;
            ans = min(mid, ans);
        }
        else {
            s = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, s;
    cin>>n>>s;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cout<<findMinPages(a, n, s)<<endl;

    return 0;   
}