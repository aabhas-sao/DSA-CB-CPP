#include <iostream>
#include <stack>
#include <climits>
using namespace std;

long long histogram(long long a[], int n) {
    stack<int> s;
    long long currentArea = 0;
    long long maxArea = INT_MIN;
    long long i = 0;

    while(i < n) {
        if(s.empty() || a[i] >= a[s.top()]) s.push(i++);
        else {
            while(!s.empty() && a[s.top()] > a[i]) {
                int top = s.top();
                s.pop();
                if(s.empty()) currentArea = a[top] * i;
                else currentArea = a[top] * (i - s.top() - 1);
                maxArea = max(currentArea, maxArea);
            }
        }
    }
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        if(s.empty()) currentArea = a[top] * i;
        else currentArea = a[top] * (i - s.top() - 1);
        maxArea = max(currentArea, maxArea);
    }

    return maxArea;
}

int main() {
    int n;
    cin >> n;
    long long a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << histogram(a, n) << endl;

    return 0;
}