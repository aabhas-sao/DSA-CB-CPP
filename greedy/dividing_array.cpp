#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, n, min, max;
    cin >> t;
    int a[100000];

    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        min = 0; max = 0;

        sort(a, a + n);
        for (int i = 0; i < n; i+=2) {
            min += abs(a[i + 1] - a[i]);
        }

        for (int i = 0; i < n / 2; i ++) {
            ind idx = (n / 2) - i;
            max += abs(a[i] - a[idx]);
        }

        cout << min << " " << max << endl;
    }

    return 0;
}