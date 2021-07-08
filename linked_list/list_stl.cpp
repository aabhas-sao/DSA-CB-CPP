#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

int main() {
	forward_list<int> f{0, 1, 2, 3};
	f.push_front(2);
	f.sort();
	f.reverse();
	for(int x: f) {
		cout<<x<<" ";
	}
	cout<<endl;
	list<int> l1{2, 3, 5, 6};
	l1.push_back(1);
	l1.sort();
	l1.reverse();
	for(int x: l1) {
		cout<<x<<" ";
	}
	return 0;
}