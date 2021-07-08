#include <iostream>
#include <string>
using namespace std;

bool isCaps(char s) {
    return (s >= 'A' and s <= 'Z');
}

void canYouReadThis(string s) {
    char c[s.length()];

    int j;
    int i = 0;
    while(i<s.length()) {
        int j = 0;
        c[j++] = s[i++];
        while(!isCaps(s[i])) {
            c[j++] = s[i++];
        }
        c[j] = '\0';
        cout<<c<<endl;
    }
}


int main() {
    string s;
    cin>>s;
    canYouReadThis(s);
    return 0;
}