#include <bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> &A, vector<vector<int> > &B) {
    int q, r, s;
    vector<int> ans;
    vector<vector<int>> dp(10000, vector<int>(10000, -1));
    
    for (int i = 0; i < A.size(); i++) {
        dp[i][i] = A[i];
    }
    
    bool invert = true;
    
    for (int i = 0; i < A.size(); i++) {
        invert = false;
        for (int j = i + 1; j < A.size(); j++) {
            if(!invert) {
                dp[i][j] = dp[i][j - 1] - A[j];
            } else {
                dp[i][j] = dp[i][j - 1] + A[j];
            }
            invert = !invert;
        }
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < 5; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    for (auto x: B) {
        q = x[0];
        r = x[1];
        s = x[2];
        if (q == 1) {
            int diff = s - A[r - 1];
            A[r - 1] = s;
            for (int i = 0; i < A.size(); i++) {
                cout << A[i] << " ";
            }
            cout << endl;
            // do some work
            bool invert = false;
            for (int i = 0; i < A.size(); i++) {
                for (int j = r - 1; j < A.size(); j++) {
                    if(!invert) dp[i][j] += diff;
                    else dp[i][j] -= diff;
                }
                invert = !invert;
            }
        } else {
            ans.push_back(dp[r - 1][s - 1]);
        }
    }
    
    for (int i = 0; i < 5; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < 5; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return ans;
}

int main() {
    vector<int> A = {1, -2, 3, 4, 5};
    vector<vector<int>> B = {{2, 1, 5}, {1, 4, -1}, {2, 1, 5}};
    cout << endl;
    for (auto x: solve(A, B)) {
        cout << x << " ";
    }
}