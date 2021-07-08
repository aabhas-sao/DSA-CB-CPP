#include <iostream>
using namespace std;

int a[1000005] = {0};
int cf[1000005];

#define ll long long int

void sieve() {
	// mark all odd nums as potential primes
    for(ll i = 3; i < 1000005; i+=2) {
        a[i] = 1;
    }

    // mark multiples of primes
    for(ll i = 3; i < 1000005; i+=2) {
        if(a[i] == 1) {
            for(ll j = i * i; j < 1000005; j = j + i) {
					a[j] = 0; // mark as not prime
            }
        }
    }

    a[0] = a[1] = 0;
    a[2] = 1;

    int z = 0;
}

void buildCf() {
    int cnt = 0;
    for(int i = 0; i < 1000005; i++) {
        if(a[i] == 1) {
            cnt++;
        }
        cf[i] = cnt;
    }
}

int main() {
    int t;
    cin>>t;
    sieve();
    buildCf();

    while(t--) {
        int n1, n2;
        cin>>n1>>n2;

		int ans = cf[n2 - 1] - cf[n1 - 1];
		cout<<ans<<endl;
    }
    return 0;
}