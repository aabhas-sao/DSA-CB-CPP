#include <iostream>
using namespace std;

void genBrackets(char c[], int i, int n, int open, int close) {
    // base case
    // cout<<"o"<<open<<endl;
    if(open == n and close == n) {
        c[2n] = '\0';
        cout<<c<<endl;
        return;
    }
    if(open > n) {
        return;
    }
    if(close > open) {
        return;
    }
    c[i] = '(';
    genBrackets(c, i + 1, n, open + 1, close);
    c[i] = ')';
    genBrackets(c, i + 1, n, open, close + 1);
}

int main() {
    int n;
    cin>>n;
    char c[2 * n + 1];
    genBrackets(c, 0, n, 0, 0);
}