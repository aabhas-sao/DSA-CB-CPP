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

node* insert(node* root, int d) {
	if(root == NULL) {
		return new node(d);
	}

	if(d <= root->data) {
		root->left = insert(root->left, d);
	}

	if(d > root->data) {
		root->right = insert(root->right, d);
	}

	return root;
}

node* deleteNode(node* root, int d) {
	if(root == NULL) {
		return NULL;
	}

	if(d == root->data) {
		if(root->left == NULL && root->right == NULL) {
			return NULL;
		} else if(root->left != NULL && root->right != NULL) {
			node* temp = root->right;
			while(temp->left != NULL) {
				temp = temp->left;
			}
			int p = root->data;
			root->data = temp->data;
			temp->data = p;
			deleteNode(root->right, d);
		} else {
			if(root->left != NULL) {
				node* temp = root->left;
				root->left = NULL;
				delete(root);
				return temp;
			} else {
				node* temp = root->right;
				root->right = NULL;
				delete(root);
				return temp;
			}
		}
	}

	if(d <= root->data) {
		root->left = deleteNode(root->left, d);
	}

	if(d > root->data) {
		root->right = deleteNode(root->right, d);
	}

	return root;
}

void preorder(node* root) {
	if(root == NULL) {
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int a[n];	
		node* root = NULL;

		for(int i = 0; i < n; i++) {
			cin >> a[i];
			root = insert(root, a[i]);
		}
		
		int m;
		cin >> m;
		int b[m];
		for(int i = 0; i < m; i++) {
			cin >> b[i];
		}
		for(int i = 0; i < m; i++) {
			root = deleteNode(root, b[i]);
		}

		preorder(root);
	}
	return 0;
}