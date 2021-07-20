#include <iostream>
using namespace std;

void classAssignment(char c[], int i, int n, char t, int* ptr) {
    if( i > 0 && c[i - 1] == 'b' &&  t == 'b') {
        return;
    }

    if(i == n - 1) {
        *ptr += 1;
        // c[i] = t;
        // c[i + 1] = '\0';
        // cout << c << endl;
        return;
    }

    

    c[i] = t;
    classAssignment(c, i + 1, n, 'a', ptr);
    classAssignment(c, i + 1, n, 'b', ptr);
}

int main() {
    int t;
    cin >> t;
    char c[26];
    for(int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        int ans = 0;
        int *ptr = &ans;
        classAssignment(c, 0, n, 'a', ptr);
        classAssignment(c, 0, n, 'b', ptr);
        cout << "#" << i << " : " << ans << endl;
    }
    return 0;
}