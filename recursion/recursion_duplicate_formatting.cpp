#include <iostream>
using namespace std;

void dup(char c[], int n) {
    // base case
    if(n == 1 || n == 0) {
        return;
    }

    // if cons elem
    if(c[0] == c[1]) {
        // make space for one *
        for(int j = n - 1; j >= 1; j--) {
            c[j + 1] = c[j];
        }
        c[1] = '*';
        return dup(c + 2, n - 1);
    } 
    cout<<c[0];
    return dup(c + 1, n - 1);
}

int main() {
    char c[10008];
    int n = 0;
    cin>>c;
    while(c[n] != '\0') {
        n++;
    }
    dup(c, n);
    cout<<n<<endl;
    cout<<c;
    return 0;
}