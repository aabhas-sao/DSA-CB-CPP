#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string a;
    string b;

    a = "abc";
    b = "acd";

    int dp[1001][1001];
    for(int i = 0; i < a.length() + 1; i++) {
        dp[i][0] = 0;
        for(int j = 0; j < b.length() + 1; j++) {
            dp[0][j] = 0;
        }
    }

    char c[1001];

    for(int i = 1; i < a.length() + 1; i++) {
        for(int j = 1; j < b.length() + 1; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    /*
    for(int i = 0; i < a.length() + 1; i++) {
        for(int j = 0; j < b.length() + 1; j++) {
            cout << dp[i][j] << " ";
       }
        cout << endl;
    }
    */

    vector<char> v;
    int i = a.length();
    int j = b.length();

    while(i != 0 && j != 0) {
        if(dp[i][j] == dp[i][j - 1]) {
            j--;
        } else if(dp[i][j] == dp[i - 1][j]) {
            i--;
        } else {
            v.push_back(a[i - 1]);
            i--;
            j--;
        }
    }

    reverse(v.begin(), v.end());

    for(auto x: v) {
        cout << x;
    }
    cout << endl;

    return 0;
}