#include <iostream>
using namespace std;

char w[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void words(int s) {
    if(s == 0) {
        return;
    }

    words(s / 10);
    int digit = s % 10;
    cout<<w[digit]<<" ";
}


int main() {
    int n;
    cin>>n;
    words(n);
    return 0;
}