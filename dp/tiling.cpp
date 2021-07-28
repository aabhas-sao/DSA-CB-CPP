#include <iostream>
using namespace std;

#define C 1000000007

long long int pureDp(int n, int m) {
    long long int c[n + 1];
    c[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        if(i < m) {
            c[i] = 1;
        } else if(i == m) {
            c[i] = 2;
        } else {
            c[i] = (c[i - 1] % C + c[i - m] % C); 
        }
    }
    return c[n] % C;
}

int tiling(int n, int m) {
    if(n < 1 || m < 1) {
        return 0;
    }
    if(n == 1 || m == 1) {
        return 1;
    }
    if(n == m) {
        return 2;
    }

    int ans = 0;

    if(n > m) {
        ans += tiling(n - m, m);
    } 
    ans += tiling(n - 1, m);
    return ans;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
    	int n, m;
    	cin >> n >> m;
    	cout << pureDp(n , m) << endl;
	}

    return 0;
}
