#include <iostream>
#include <vector>
using namespace std;

class minMaxStack {
private: 
	vector<int> stack;
	vector<int> min_stack;
	vector<int> max_stack;

public:
	int top() {
		return stack[stack.size() - 1];
	}

	void pop() {
		stack.pop_back();
		min_stack.pop_back();
		max_stack.pop_back();
	}

	void push(int x) {
		int current_min = x;
		int current_max = x;

		if(min_stack.size()) {
			current_min = min(min_stack[min_stack.size() - 1], current_min);
			current_max = max(max_stack[max_stack.size() - 1], current_max);
		}

		min_stack.push_back(current_min);
		max_stack.push_back(current_max);
		stack.push_back(x);
	}

	int get_min() {
		return min_stack[min_stack.size() - 1];
	}

	int get_max() {
		return max_stack[max_stack.size() - 1];
	}

	bool empty() {
		return stack.size() == 0;
	}

	void print() {
		for(int x: stack) {
			cout<<x<<" ";
		}
		cout<<endl;
		for(int x: min_stack) {
			cout<<x<<" ";
		}
		cout<<endl;
		for(int x: max_stack) {
			cout<<x<<" ";
		}
		cout<<endl;
	}
};

int main() {
	minMaxStack s;
	s.push(5);
	s.push(3);
	s.push(1);
	s.push(7);
	s.push(9);
	s.print();
	s.pop();
	cout<<s.get_max()<<endl;
	cout<<s.get_min()<<endl;
	return 0;
}