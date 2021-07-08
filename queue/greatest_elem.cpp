#include <iostream>
#include <queue>
using namespace std;

void solution(int a[], int n) {
	queue<int> q;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i - 1]) {
			q.push(a[i]);
		}
	}

	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
	
	// for(int i = 0; i < n; i++) {
	// 	if(q.front() <= a[i]) {
	// 		q.pop();
	// 	}
	// 	if(q.empty()) {
	// 		cout<<"-1"<<" ";
	// 	}
	// 	else if(q.front() > a[i]) {
	// 		cout<<q.front()<<" ";
	// 	}
	// }
}

int main() {
	int n;
	cin>>n;
	int a[n];
	
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	
	solution(a, n);

	return 0;
}