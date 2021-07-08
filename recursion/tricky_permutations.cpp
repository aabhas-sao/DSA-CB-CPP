#include <iostream>
#include <set>
#include <string>
using namespace std;

set<string> s;

void permutations(char * c, int i) {
    // base case
    if(c[i] == '\0') {
        s.insert(c);
        return;
    }

    // rec case
    for(int j = i; c[j] != '\0'; j++) {
        swap(c[i], c[j]);
        permutations(c, i + 1);
        swap(c[i], c[j]);
    }
}

int main() {
    char c[100];
    cin>>c;
    permutations(c, 0);
	for(string x: s) {
		cout<<x<<endl;
	}
    return 0;
}