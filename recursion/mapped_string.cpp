#include <iostream>
#include <string>
using namespace std;

char alphabet[27];

void mappedString(
    string s, 
    char c[],
    int idx, 
    int i,
    int len
) {
    // base case
    if(i >= len) {
        c[idx] = '\0';
        string p(c);
        cout << p << endl;
        return;
    }

    c[idx] = alphabet[s[i] - '0'];
    mappedString(s, c, idx + 1, i + 1, len);
    
    if(i == len - 1) return;
    int alphaNo = (s[i] - '0') * 10 + s[i + 1] - '0';
    if(alphaNo > 26) {
        return;
    }
    c[idx] = alphabet[alphaNo];

    mappedString(s, c, idx + 1, i + 2, len);
}

int main() {
    int n;
    cin >> n;
    string s = to_string(n);

    char c[20]; 

    for(int i = 1; i <= 26; i++) {
        alphabet[i] = 'A' + i - 1;
    }

    mappedString(s, c, 0, 0, s.length());

    return 0;
}