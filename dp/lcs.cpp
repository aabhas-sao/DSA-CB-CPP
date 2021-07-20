#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int lcs(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
    if(i >= s1.length() || j >= s2.length()) {
        return 0;
    }

    if(dp[i][j] != -1) {
        cout << dp[i][j] << endl;
        return dp[i][j];
    }

    if(s1[i] == s2[j]) {
        return dp[i][j] =  1 + lcs(s1, s2, i + 1, j + 1, dp);
    } 
    int op1 = lcs(s1, s2, i + 1, j, dp);
    int op2 = lcs(s1, s2, i, j + 1, dp);

    return dp[i][j] = max(op1, op2);
}

int main() {
    vector<vector<int>> dp(10, vector<int>(10, -1));
    cout << lcs("ABDC", "ADGBE", 0, 0, dp) << endl;
    for(auto x: dp) {
        for(auto y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}