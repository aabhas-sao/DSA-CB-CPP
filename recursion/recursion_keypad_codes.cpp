#include <iostream>
#include <cstring>
using namespace std;

string keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void keypadCode(string s, char c[], int i, int j, int* count) {
    if(j >= s.length()) {
        *count += 1;
        c[i] = '\0';
        cout << c << " ";
        return;
    }

    int pos = s[j] - '0' - 1;
    string p = keypad[pos];

    for(int k = 0; k < p.length(); k++) {
        c[i] = p[k];
        keypadCode(s, c, i + 1, j + 1, count);
    }
}

int main() {
    string in;
    char c[1001];
    cin >> in;
    int count = 0;
    int *ptr = &count;
    keypadCode(in, c, 0, 0, ptr);
    cout << endl << count << endl;
    return 0;
}