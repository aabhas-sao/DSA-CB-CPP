#include <iostream>
using namespace std;

bool isPrime(int n) {
    if(n == 0 || n == 1) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i * i <= n; i++) {
        cout << i << endl;
        if(n % i == 0) return false;
    }

    return true;
}

int nextPrime(int n) {
    n++;
    while(!isPrime(n)) {
        n++;
    }
    return n;
}

int main() {
    cout << isPrime(9);
}