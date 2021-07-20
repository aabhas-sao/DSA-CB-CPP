#include <iostream>
using namespace std;

bool canIPlaceOpenBracket(int open, int n) {
    if(open == n) {
        return false;
    }
    return true;
}

bool canIPlaceClosingBracket(int open, int close) {
    if(open == close) {
        return false;
    }
    return true;
}

void genParenthesis(int n, char c[], int i, int open, int close) {
    // base case
    if(open + close >= 2 * n) {
        c[i] = '\0';
        cout << c << endl;
        return;
    }
    
    // recursive case
    if(canIPlaceClosingBracket(open, close)) {
        c[i] = ')';
        genParenthesis(n, c, i + 1, open, close + 1);
    }
    if(canIPlaceOpenBracket(open, n)) {
        c[i] = '(';
        genParenthesis(n, c, i + 1, open + 1, close);
    }
}

int main() {
    int n; 
    cin >> n;
    char c[23];
    genParenthesis(n, c, 0, 0, 0);
    return 0;
}