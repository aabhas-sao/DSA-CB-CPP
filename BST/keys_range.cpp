#include <iostream>
#include <algorithm>
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

void inorder(node * root, int p, int q) {
	if(root == NULL) {
		return;
	}

	inorder(root->left, p, q);
	if(root->data >= p && root->data <= q) {
		cout<<root->data<<" ";
	}
	inorder(root->right, p, q);
}

node * insert(node * root, int d) {
	if(root == NULL) {
		return new node(d);
	}

	if( d > root->data ) {
		root->right = insert(root->right, d);
	}
	if( d <= root->data ) {
		root->left = insert(root->left, d);
	}

	return root;
}

int main() {
	int t;
	cin>>t;
	int a[50];
	while(t--) {
		int n;
		cin>>n;

		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}

		int p, q;
		cin >> p >> q;


		node * root = NULL;

		for(int i = 0; i < n; i++) {
			root = insert(root, a[i]);
		}
			
		cout << "# Preorder : ";
		preOrder(root);
		cout<<endl;
		cout<<"# Nodes within range are : ";
		inorder(root, p, q);
		cout << endl;
	}
	return 0;
}