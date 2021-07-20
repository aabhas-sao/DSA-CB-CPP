#include <iostream>
using namespace std;

int winesTopDown(int wines[], int i, int j, int dp[][100], int y) {
    if ( i > j ) {
        return 0;
    }

    if(dp[i][j] != 0) {
        return dp[i][j];
    }

    int op1 = y * wines[i] + winesTopDown(wines, i + 1, j, dp, y + 1);
    int op2 = y * wines[j] + winesTopDown(wines, i, j - 1, dp, y + 1);
    return dp[i][j] = max(op1, op2);
}

int main() {
    int dp[100][100] = {0};

    int wines[] = {2, 3, 5, 4};
    int n = sizeof(wines) / sizeof(int);
    cout << n << endl;
    cout << winesTopDown(wines, 0, n - 1, dp, 1) << endl;
    return 0;
}