#include <iostream>
using namespace std;

void sti(char c[], int ans) {
    if(c[0] == '\0') {
        cout<<ans<<endl;
        return;
    }
    int p = c[0] - '0';
    ans = ans * 10 + p;
    
    sti(c + 1, ans);
}

int main() {
    char c[100005] = "123";
    sti(c, 0);
    return 0;
}