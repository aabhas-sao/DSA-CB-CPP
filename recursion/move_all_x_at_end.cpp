#include <iostream>
#include <string>
using namespace std;

void moveXEnd(char s[], int i, int n) {
    if(i == n - 1) {
        return;
    }

    moveXEnd(s, i + 1, n);

    if(s[i] == 'x') {
        while(i < n - 1 && s[i + 1] != 'x') {
            swap(s[i], s[i + 1]);
            i++;
        }
    }
}

int main() {
    string n;
    cin >> n;
    char s[n.length() + 1];

    for(int i = 0; i < n.length(); i++) {
        s[i] = n[i];
    }

    moveXEnd(s, 0, n.length());

    s[n.length()] = '\0';

    string ans(s);
    cout << ans << endl;
    return 0;
}