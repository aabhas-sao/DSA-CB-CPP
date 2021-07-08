#include <iostream>
#include <list>
using namespace std;

bool palindrome(list<int> l) {
	if(l.size() == 0) {
		return false;
	}
	list<int>::iterator a = l.begin();
	auto b = l.end();
	b--;
	while(a != b) {
		if(*a != *b) {
			return false;
		}
		a++;
		b--;
	}

	return true;
}

int main() {
	int n = 5;
	// 5
// 1 2 3 6 8
	// cin>>n;
	int a[n] = {1, 2, 3, 2, 1};
	// for(int i = 0; i < n; i++) {
	// 	cin>>a[i];
	// }
	list<int> l (a, a + n);
	cout<<palindrome(l)<<endl;
	return 0;
}