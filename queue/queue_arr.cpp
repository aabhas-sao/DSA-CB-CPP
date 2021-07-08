#include <iostream>
using namespace std;

class Queue {
	int * arr;
	int f, r, cs, ms;
public:
	Queue(int d = 5) {
		arr = new int[d];
		f = 0;
		r = d - 1;
		cs = 0;
		ms = d;
	}

	int size() {
		return cs;
	}

	bool full() {
		return ms == cs;
	}

	bool empty() {
		return cs == 0;
	}

	void push(int val) {
		if(!full()) {
			r = (r + 1) % ms;
			arr[r] = val;
			cs++;
		}
	}

	void pop() {
		if(!empty()) {
			f = (f + 1) % ms;
			cs--;
		}
	}

	int front() {
		return arr[f];
	}

	void print() {
		for(int i = f; i < r; i++) {
			cout<<arr[i]<<" ";
		}
	}

	~Queue() {
		if(arr != NULL) {
			delete [] arr;
			arr  =NULL;
		}
	}
};

int main() {
	Queue q;
	for(int i = 1; i <= 5; i++) {
		q.push(i);
	}
	q.pop();
	q.pop();
	q.push(7);
	while(!q.empty()) {
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}