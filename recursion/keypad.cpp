#include <iostream>
using namespace std;

char keypadVals[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void keypad(char * input, char * output, int i, int j) {
    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        cout<<output<<endl;
        return;
    }
    int digit = input[i] - '0';
    // rec
    for(int k = 0; keypadVals[k][i] != '\0'; k++) {
        keypad(input, output, i + 1, j + 1);
    }
}

int main() {
    char input[100];
    cin>>input;
    char output[100];
    keypad(input, output, 0, 0);
    return 0;
}