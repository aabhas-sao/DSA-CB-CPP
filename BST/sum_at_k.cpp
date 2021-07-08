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

node * buildtree() {
	int d, n;
	cin>>d>>n;

	node * root = new node(d);

	if(n == 0) {
		return root;
	} else if(n==1){
        root->left = buildtree();
        return root ;
    } else {
    	root->left = buildtree();
		root->right = buildtree();
		return root;
    }
}

void preOrder(node * root) {
	if(root == NULL) {
		return;
	}

	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int sumAtK(node * root, int k) {
	if(root == NULL) {
		return 0;
	}

	if(k == 0) {
		return root->data;
	}
	int l = sumAtK(root->left, k - 1);
	int r = sumAtK(root->right, k - 1);

	return l + r;
}

int main() {
	node * root = buildtree();

	// preOrder(root);
	int k;
	cin>>k;
	cout << sumAtK(root, k) << endl;
	return 0;
}