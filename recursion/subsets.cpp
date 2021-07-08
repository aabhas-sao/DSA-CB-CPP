#include <iostream>
using namespace std;

void subsets(char input[], char output[], int i, int j) {
    // base case
    if(input[i] == '\0') {
        output[j] = '\0';
        cout<<output<<" ";
        return;
    }
    subsets(input, output, i + 1, j);
    output[j] = input[i];
    subsets(input, output, i + 1, j + 1);
}

int main() {
    char input[100];
    char output[100];
    cin>>input;
    subsets(input, output, 0, 0);
    return 0;
}