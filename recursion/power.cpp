#include <iostream>
using namespace std;

int pow(int a, int n ) {
    //base case
    if(n == 0) return 1;
    return a * pow(a, n - 1);
}

int main() {
    cout<<pow(4, 0);
    return 0;
}