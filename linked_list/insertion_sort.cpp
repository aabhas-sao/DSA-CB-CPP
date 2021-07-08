#include <iostream>
#include <list>
using namespace std;

void insertion_sort(list<int>& l) {
	auto a = l.begin();
	a++;
	while(a != l.end()) {
		auto c = a;
		cout<<*c<<endl;
		do {
			auto p = c;
			auto j = c--;
			if(*j > *p) {
				// cout<<*c<<endl;
				swap(*j, *p);
			}
			auto t = j;
			
		} while(c != l.begin());
		a++;
	}
}

int main() {
	int n = 5;
	// 5
	// 1 2 3 6 8
	// cin>>n;
	int a[n] = {2, 3, 4, 1, 5};
	// for(int i = 0; i < n; i++) {
	// 	cin>>a[i];
	// }
	list<int> l (a, a + n);

	insertion_sort(l);

	for(int x: l) {
		cout<<x<<" ";
	}
	return 0;
}