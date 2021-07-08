#include<iostream>
using namespace std;

int main() {
    unsigned int n;
    cin>>n;
    string s = to_string(n);
    int i = 0;
    if(s[0] == '9') {
        i++;
    }
    for(; i < s.length(); i++) {
        if(s[i] >= 53) {
            s[i] = 48 + 57 - s[i];
            cout<<s[i]<<endl;
        }
    }
    cout<<s;
    return 0;
}