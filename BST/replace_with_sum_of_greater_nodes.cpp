#include <iostream>
using namespace std;

class node {
public:
	int data;
	node * left;
	node * right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* BST(int a[], int s, int e) {
	// base case
	if(s > e) {
		return NULL;
	}

	int m = (s + e) / 2;
	node * root = new node(a[m]);

	root->left = BST(a, s, m - 1);
	root->right = BST(a, m + 1, e);

	return root;
}

void greater_sum(node * root) {
	static int sum = 0;
	if(root == NULL) {
		return;
	}
	root->data += sum;
	cout << root->data << " ";

	greater_sum(root->right);
	greater_sum(root->left);
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	node * root = BST(a, 0, n - 1);

	return 0;
}