#include <iostream>
using namespace std;

void str_dup(char c[], int n) {
    // base case
    if(n == 1) {
        c[1] = '\0';
        return;
    }
    
    if(c[0] == c[1]) {
        for(int i = 1; i < n - 1; i++) {
            c[i] = c[i + 1];
        }
        str_dup(c, n - 1);
    }
    str_dup(c + 1, n - 1);
}

int main() {
    char c[1000];
    int n = 0;
    cin>>c;
    while(c[n] != '\0') {
        n++;
    }
    str_dup(c, n);
    cout<<c;
    return 0;
}