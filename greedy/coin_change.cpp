#include <iostream>
#include <algorithm>
using namespace std;

int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000};

int coinChange(int n) {
    int ans = 0;
    while(n > 0) {
        int *idx = upper_bound(coins, coins + 10, n);
        --idx;
        n -= *idx;
        ans++;
    }
    return ans;
}

int main() {
    cout << coinChange(8);    
    return 0;
}