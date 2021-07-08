#include <iostream>
using namespace std;

void form_array(int a[], int n, int zeros, int ones, int twos) {
    while(zeros--) {
        a[i] = 0;
    }
    while(ones--) {
        a[i] = 1;
    }
    while(twos--) {
        a[i] = 2;
    }
}

void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;
    int zeros = 0;
    int ones = 0;
    int twos = 0;

    for(int i = 0; i < n; i++){
        int s;
        cin>>s;
        if(s == 0) {
            zeros++;
        }
        else if(s == 1) {
            ones++;
        }
        else {
            twos++;
        }
    }
    form_array(a, n, zeros, ones, twos);
    display(a, n);
    return 0;
}