#include <iostream>
using namespace std;

int fastPow(int a, int n) {
    // base case 
	if(n == 0) {
		return 1;
	}
    // recuring case
    int sq = fastPow(a, n / 2);
    sq *= sq;
    if(n&1) {
        return sq * a;
    }
    return sq;
}

int main() {
    int a;
    cin>>a;
    int n;
    cin>>n;
    cout<<fastPow(a, n)<<endl;
    return 0;
}