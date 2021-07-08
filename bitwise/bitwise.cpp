#include <iostream>
using namespace std;

int unique_number(int a[], int n) {
    int ans = a[0];
    for(int i = 1; i < n; i++) {
        ans = ans ^ a[i];
        // cout<<ans<<endl;
    }
    return ans;
}

bool isOdd(int n) {
    int c = 1;
    if(n & c == 1) {
        return true;
    }
    return false;
}

int clearLastiBits(int n, int i) {
    int mask = (~0)<<i;
    return mask & n;
}

int clearRangeBits(int n, int i, int j) {
    int a = (~0)<<(j + 1);
    int b = 1<<i - 1;
    int mask = a | b;
    return n & mask;
}

void find_ith_bit(int n, int i) {
    int a = 1;
    a = a<<i;
    int c = a & n;
    if(c > 0) {
        cout<<"bit was 1";
    }
    else {
        cout<<"bit was 0";
    }
}

int main() {
    // int arr[] = {2, 3, 2, 4, 3, 4, 5, 6, 6};
    // int n = 9;
    // cout<<unique_number(arr, n)<<endl;
    // cout<<"is odd? "<<isOdd(46)<<endl;
    // cout<<clearLastiBits(31, 4)<<endl;
    // cout<<clearRangeBits(31, 1, 3)<<endl;
    return 0;
}
