#include <iostream>
using namespace std;

void permutations(char * c, int i) {
    // base case
    if(c[i] == '\0') {
        cout<<c<<endl;
        return;
    }

    // rec case
    for(int j = i; c[j] != '\0'; j++) {
        swap(c[i], c[j]);
        permutations(c, i + 1);
        swap(c[i], c[j]);
    }
}

int main() {
    char c[100];
    cin>>c;
    permutations(c, 0);
    return 0;
}