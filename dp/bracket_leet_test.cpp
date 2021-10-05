#include <bits/stdc++.h>
using namespace std;

void genParenthesis(int i, int open, int close, int n, char c[], vector<string>& v) {
    // base case
    if (open == 0 && close == 0) {
        c[i] = '\0';

        cout << c << endl;

        string s(c);
        v.push_back(s);
        return;
    }

    if (open > 0) {
        c[i] = '(';
        genParenthesis(i + 1, open - 1, close, n, c, v);
    }

    if (open < close) {
        c[i] = ')';
        genParenthesis(i + 1, open, close - 1, n, c, v);

    }

}

vector<string> generateParenthesis(int n) {
    vector<string> parenthesis;
    parenthesis.reserve(n);
    char c[(2 * n) + 1];
    genParenthesis(0, n, n, n, c, parenthesis);

    return parenthesis;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n; cin >> n;
    for (auto x : generateParenthesis(n)) {
        cout << x << endl;
    }
    return 0;
}