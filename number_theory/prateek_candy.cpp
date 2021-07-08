#include <iostream>
using namespace std;

#define ll long long int

int a[1000005] = {0};
int primes[1000000];

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

    for(int i = 0; i < 1000005; i++) {
        if(a[i] == 1) {
            primes[z++] = a[i];
        }
    }
}

void nthPrime(int n) {
	cout<<primes[n-1]<<endl;
}

int main() {
	int t;
	cin>>t;
	sieve();
	while(t--) {
		int n;
		cin>>n;
		nthPrime(n);
	}
}