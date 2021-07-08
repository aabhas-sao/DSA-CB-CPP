#include <iostream>
using namespace std;

void replace_pi(char c[], int n) {
    // base case
    if(n == 0 || n == 1) {
        return;
    }

    // rec case 
    if(c[0] == 'p' && c[1] == 'i') {
        // shift i + 3 and i + 4 and shift the other elements
        for(int j = n - 1; j >= 2; j--) {
            c[j + 2] = c[j];
        }
        c[0] = 51;
        c[1] = '.';
        c[2] = 49;
        c[3] = 52;
        cout<<c[0]<<c[1]<<c[2]<<c[3];
        return replace_pi(c + 4, n - 2);
    }
    cout<<c[0];
    return replace_pi(c + 1, n - 1);
}

template <typename T>
void display(T c[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<c[i];
    }
}

int main() {
    // int t;
    // cin>>t;
    // while(t--) {

    // }
    char *c = {'b', 'a', 'p', 'i', 'p', 'i', 's', 'o', 'p', 'i'};
    c = &s[0];
    display(c, n);
    replace_pi(c, n);
    cout<<endl;
    return 0;
}