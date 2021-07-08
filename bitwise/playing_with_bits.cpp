#include <iostream>
#include <algorithm>
using namespace std;

int countSetBit(int a) {
    int count = 0;
    int i = 1;
    while(a > 0) {
        if(a&i) {
            count++;
        }
        a = a>>1;
    }
    return count;
}

int play(int a, int b) {
    if(b < a) swap(a,b);
    int ans = 0;
    for(int i = a; i <= b; i++) {
        ans += countSetBit(i);
    }    
    return ans;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a, b;
        cin>>a>>b;
        cout<<play(a, b)<<endl;
    }
    return 0;
}