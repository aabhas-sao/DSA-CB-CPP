#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
    int c[128] = {0};
    string s;
    cin>>s;

    for(int i=0; i<s.length(); i++) {
        c[s[i]]++;
    }

    int highest = INT_MIN;
    int highestIndex;

    for(int i=0; i<128; i++) {
        if(c[i] > highest) {
            highest = c[i];
            highestIndex = i;
        }
    }

    cout<<(char)highestIndex<<endl;

    return 0;
}