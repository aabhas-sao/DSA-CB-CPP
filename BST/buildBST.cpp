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

node * buildBST(int a[], int s, int e) {
	
	if(s > e) {
		return NULL;
	}

	int mid = (s + e) / 2;
	node * root = new node(a[mid]);

	root->left = buildBST(a, s, mid - 1);
	root->right = buildBST(a, mid + 1, e);

	return root;
}

void preOrder(node * root) {
	if(root == NULL) {
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	int n = 7;
	// cin>>n;
	int a[n] = {1, 2, 3, 4, 5, 6, 7};
	
	node * root = buildBST(a, 0, n - 1);

	preOrder(root);

	return 0;
}