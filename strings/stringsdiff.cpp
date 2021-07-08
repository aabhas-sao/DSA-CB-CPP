#include <iostream>
#include <string>
using namespace std;

void sdiff(string s) {
    int l = s.length();
    char c[3 * l];
    int j = 0;
    for (int i = 0; i < l - 1; i++) {
        cout<<j<<endl;
        c[j] = s[i];
        int x = s[i + 1] - s[i];
        if(x < 0) {
            c[++j] = 45;
            c[++j] = 48 + (-1 * x);
        } else {
            c[++j] = 48 + x;
        }
        j++;
        cout<<c[i]<<endl;
    }
    c[j] = s[l-1];
    c[j + 1] = '\0'; 
    cout<<c<<endl;
}

int main() {
    string s;
    cin >> s;
    sdiff(s);
    // char c = 49;
    // cout<<c;
    return 0;
}