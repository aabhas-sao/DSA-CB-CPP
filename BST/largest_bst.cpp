#include <iostream>
#include <climits>
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

bool isBST(node* root, int maxV, int minV) {
	if(root == NULL) {
		return true;
	}

	if(root->data >= minV && root->data < maxV && isBST(root->left, root->data, minV) && isBST(root->right, maxV, root->data)) {
		return true;
	}
	return false;
}

int count(node* root) {
	if(root == NULL) {
		return 0;
	}

	int l = count(root->left);
	int r = count(root->right);

	return l + r + 1;
}

int largestBST(node* root) {
	if(root == NULL) {
		return 0;
	}

	if(isBST(root, INT_MAX, INT_MIN)) {
		return count(root);
	}

	int l = largestBST(root->left);
	int r = largestBST(root->right);

	return max(l, r);
}

node * treeFromPreIn(int pre[], int in[], int s, int e) {
	static int index = 0;

	// base case
	if(s > e) {
		return NULL;
	}

	node * root = new node(pre[index]);
	
	int m;

	for(int j = s; j <= e; j++) {
		if(pre[index] == in[j]) {
			m = j;
			break;
		}
	}

	index++;

	root->left = treeFromPreIn(pre, in, s, m - 1);
	root->right = treeFromPreIn(pre, in, m + 1, e);

	return root;
}

int main() {
	int n;
	cin >> n;
	int pre[n];
	int in[n];
	node* root = treeFromPreIn(pre, in, 0, n - 1);
	
	cout << largestBST(root);
	return 0;
}