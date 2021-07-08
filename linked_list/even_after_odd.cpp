#include <iostream>
using namespace std;

class node {
public:
	int data;
	node * next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void eao(node * root) {
	node * ans = new node(-1);
	node * ans_it = ans;

	node * it = root;

	while(it != NULL) {
		if(it->data % 2 != 0) {
			ans_it->next = new node(it->data);
			ans_it = ans_it->next;
		}
		it = it->next;
	}

	it = root;

	while(it != NULL) {
		if(it->data % 2 == 0) {
			ans_it->next = new node(it->data);
			ans_it = ans_it->next;
		}
		it = it->next;
	}

	node * toD = ans;
	ans = ans->next;
	toD->next = NULL;


	while(ans != NULL) {
		cout<<ans->data<<" ";
		ans = ans->next;
	}

	cout<<endl;
}

int main() {
	int n, x;
	cin >> n;
	cin >> x;

	node * root = new node(x);
	node * it = root;

	for(int i = 1; i < n; i++) {
		int v;
		cin >> v;
		node * temp = new node(v);
		it->next = temp;
		it = it->next;
	}

	it = root;

	eao(root);

	return 0;
}