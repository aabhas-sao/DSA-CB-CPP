#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> k;
    int i = 0;

    deque<int> d;

    for(; i < k; i++) {
        while(!d.empty() && a[i] >= a[d.back()]) {
            d.pop_back();
        }
        d.push_back(i);
    }

    for (; i < n; i++) {
        cout << a[d.front()] << " ";

        // remove element that are not part of the window
        while (!d.empty() && d.front() <= i - k) {
            d.pop_front();
        }

        // remove unuseful elements
        while (!d.empty() && a[i] >= a[d.back()]) {
            d.pop_back();
        }

        d.push_back(i);
    }

    cout << a[d.front()] << endl;

    return 0;
}