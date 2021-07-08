#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template<typename T>
void display(T a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i]<<endl;
    }
}

bool compare(string a, string b) {
    int i = 0;
    int j = 0;
    while(i < a.length() and j < b.length()) {
        if(a[i] != b[j]) {
            return a[i] < b[j];
        }
        i++; j++;
    }
    return a.length() > b.length();
}

int main() {
    int n;
    cin>>n;
    string a[n];
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    sort(a, a + n, compare);
    display(a, n);
    return 0;
}