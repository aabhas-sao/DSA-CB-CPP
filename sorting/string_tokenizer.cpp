#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char* s, char delim) {
    static char* input = NULL;
    if(s != NULL) {
        input = s;
    }

    if(input == NULL) {
        return NULL;
    }

    char* output = new char[strlen(input) + 1];

    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != delim) {
            output[i] = input[i];
        }
        else {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }
    }
    output[i] = '\0';
    input = NULL;
    return output;
}

int main() {

    char word[100] = "hello world";
    char* ptr = mystrtok(word, ' ');
    cout<<ptr<<endl;
    while(ptr!=NULL) {
        ptr = mystrtok(NULL, ' ');
        cout<<ptr<<endl;
    }
    return 0;
}