#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];        
    }
    int ans = 0;

    unordered_map<int, int> s;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while(j < n && u[a[j]] == 0) {
            u[a[j]]++;
            j++;
        }
        ans += (j - i + 1) * (j - i ) / 2;
        u[a[i]]--;
    }

    cout << ans << endl;

    return 0;
}