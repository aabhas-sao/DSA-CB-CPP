#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

bool compare(int a, int b) {
    string as = to_string(a);
    string bs = to_string(b);

    string ass = as + bs;
	string bss = bs + as;
	return ass > bss;
}


void display(int a[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<a[i];
    }
}

void bignum(int a[], int n) {
    sort(a, a + n, compare);
    display(a, n);
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++) {
            cin>>a[i];
        }
        bignum(a, n);
		cout<<endl;
    }
}