#include <iostream>
using namespace std;

struct node {
	int data;
	node * next;
};

class Queue {
	node * head;
	node * tail;
public:
	Queue() {
		head = NULL;
		tail = NULL;
	}
	void push(int val) {
		node * newNode = new node();
		newNode->data = val;
		if(head == NULL) {
			head = newNode;
			tail = head;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}
	}

	void pop() {
		node * toDelete = head;
		head = head->next;
		delete toDelete;
	}

	int front() {
		return head->data;
	}

	bool empty() {
		return head == NULL;
	}

	~Queue() {
		delete head;
		delete tail;
	}
};

int main() {
	Queue q;
	for (int i = 0; i < 6; ++i)	{
		q.push(i);
	}
	// q.pop();
	// q.pop();
	// q.push(9);

	while(!q.empty()) {
		cout<<q.front()<<endl;
		q.pop();
	}
	return 0;
}