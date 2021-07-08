#include <iostream>
using namespace std;

void minToOne(int dp[], const int n = 1000) {
    dp[0] = 0;
    dp[1] = 0;
    for(int i = 2; i < n; i++) {
        const int one = dp[i - 1];
        if(i % 2 == 0) {
            const int two = dp[i / 2];
            if(i % 3 == 0) {
                const int three = dp[i / 3];
                dp[i] = min(min(one, two), three) + 1;
            } else {
                dp[i] = min(one, two) + 1;
            }
        } else if(i % 3 == 0){
            dp[i] = dp[i / 3] + 1;
        } else {
            dp[i] = dp[i - 1] + 1;
        }
    }
}

int main() {
    int dp[1000];
    minToOne(dp);
    cout << dp[14] << endl;
    

    return 0;
}