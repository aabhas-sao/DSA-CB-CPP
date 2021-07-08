#include <iostream>
using namespace std;

float square_root(int n, int p) {
    int s = 0;
    int e = n;
    float ans;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (mid * mid == n) {
            return mid;
        }
        if (mid * mid < n)  {
            s = mid + 1;
            ans = mid;
        }
        else {
            e = mid - 1;
        }
    }
    float inc = 0.1;
    while(p--) {
        while(ans*ans < n) {
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }
    return ans;
}

int main()  {
    int n;
    int p;
    cin >> n >> p;
    cout<<square_root(n, p)<<endl;
    return 0;
}