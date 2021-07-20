#include <iostream>
#include <cstring>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void smartKeypad(string s, char c[], int i, int j) {
    // base case
    if(j >= s.length()) {
        c[i] = '\0';
        cout << c << endl;
        return;
    }
    int pos = s[i] - '0';
    string p = table[pos];
    for(int k = 0; k < p.length(); k++) {
        c[i] = p[k];
        smartKeypad(s, c, i + 1, j + 1);
    }
}

int main() {
    string s;
    char c[11];
    cin >> s;
    smartKeypad(s, c, 0, 0 );
    return 0;
}