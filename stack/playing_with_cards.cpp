#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define PRIME_ARRAY_SIZE 15500000

int primes[PRIME_ARRAY_SIZE] = {0};

void primeNums() {
    int len = PRIME_ARRAY_SIZE;
    primes[0] = 1;
    primes[1] = 1;
    for(int i = 4; i < len; i++) {
        if(i % 2 == 0) {
            primes[i] = 1;
        }
    }

    for(int i = 3; i < len; i += 2) {
        if(primes[i] == 0) {
            for(int j = 2; j * i < len; j++) {
                primes[j * i] = 1;
            }
        }
    }
}

void playingWithCards(int a[], int n, int q, vector<int> p) {
    stack<int> s;

    // push cards of array to stack A 1
    for(int i = 0; i < n; i++) {
        s.push(a[i]);
    }

    vector<int> dustbin;
    vector<vector<int>> b (q);

    for(int i = 0; i < q; i++) {
        while(!s.empty()) {
            int x = s.top();
            s.pop();
            if(x % p[i] == 0) {
                b[i].push_back(x);
            } else {
                dustbin.push_back(x);
            }
        }

        for(auto x: dustbin) {
            s.push(x);
        }

        dustbin.clear();
    }

    for(auto x: b) {
        for (int i = x.size() - 1; i >= 0; i--) {
            cout << x[i] << endl;
        }
    }

    // A qth pile
    while(!s.empty()) {
        int x = s.top();
        cout << x << endl;
        s.pop();
    }
}

int main() {
    // input
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // calculate first 100000 prime numbers
    vector<int> p;
    primeNums();
    for(int i = 0; i < PRIME_ARRAY_SIZE; i++) {
        if(primes[i] == 0) {
            p.push_back(i);
        }
    }


    playingWithCards(a, n, q, p);

    // for(int i = 0 ; i < 100; i++) {
    //     if(primes[i] == 0) {
    //         cout << i << "  is prime" << endl;
    //     }
    //     else {
    //         cout << i << endl;
    //     }
    // }
    // cout << p.size() << endl;
    return 0;
}