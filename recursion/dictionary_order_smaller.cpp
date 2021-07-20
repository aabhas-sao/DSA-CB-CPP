#include <iostream>
#include <set>
#include <cstring>
using namespace std;

void permutations(char c[], int i, set<string>& m) {
    if(c[i] == '\0') {
        m.insert(c);
    }

    for(int j = i; c[j] != '\0'; j++) {
        swap(c[i], c[j]);
        permutations(c, i + 1, m);
        swap(c[i], c[j]);
    }
}

int main() {
    string s;
    cin >> s;
    char c[26];
    set<string> m;
    int i = 0;
    for(; i < s.length(); i++) {
        c[i] = s[i];
    }
    c[i] = '\0';    
    permutations(c, 0, m);

    for(auto x: m) {
        if(x < s) {
            cout << x << endl;
        }
    }
}