#include<iostream>

using namespace std;

#define ll long long int

void sieve(int a[], int n) {
    // mark all
    for(int i = 3; i <= n; i+=2) {
        a[i] = 1;
    }

    for(ll i = 3; i <= n; i+=2) {
        if(a[i] == 1) {
            for(ll j = i * i; j <= n; j = j + i) {
                a[j] = 0;
            }
        }
    }

    a[2] = 1;
    a[1] = a[0] = 0;
}

int main() {
	int n;
    cin>>n;
    int c = 1000000;
    int p[c] = {0};
    sieve(p, c);

    int count = 1;

    for(int i = 0; i < c; i++) {
        if(p[i] == 1) {
            if(count == n) {
                cout<<i<<endl;
                break;
            }
            count++;
        }
    }
    return 0;
}