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

node* constructTree(int * in, int * post, int s, int e) {
	static int index = e;

	if(s > e) {
		return NULL;
	}

	node * root = new node(post[index]);
	
	int m = -1;
	for(int j = s; j <= e; j++) {
		if(in[j] == post[index]) {
			m = j;
			break;
		}
	}

	// cout<< m << " "<< e <<endl;

	index--;

	root->right = constructTree(in, post, m + 1, e);
	root->left = constructTree(in, post, s, m - 1);

	return root;
}

void printKthLevel(node * root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 1) {
		cout<<root->data<<" ";
	}
	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
}

int height(node * root) {
	if(root == NULL) {
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);

	return max(l, r) + 1;
}

void levelOrder(node * root) {
	int h = height(root);

	for(int i = 1; i <= h; i++) {
		printKthLevel(root, i);
		cout<<endl;
	}
}

int nodesAtK(node * root, int target, int k) {
	// base case
	if(root == NULL) {
		return -1;
	}

	if(root->data == target) {
		printKthLevel(k);
		return 0;
	}

	int DL = nodesAtK(root->left, target, k);
	if(DL != -1) {
		if(DL + 1 == k) {
			cout<<root->data<<" ";
		} else {
			printKthLevel(root->right, target, k - DL - 2);
		}
		return DL + 1;
	}

	int DR = nodesAtK(root->left, target, k);
	if(DR != -1) {
		if(DR + 1 == k) {
			cout<<root->data<<" ";
		} else {
			printKthLevel(root->right, target, k - DR - 2);
		}
		return DR + 1;
	}

	return -1;
}

int main() {
	int in[] = { 4, 2, 6, 5, 7, 1, 3, 8};
	int post[] = { 4, 6, 7, 5, 2, 8, 3, 1};
	int n = 8;

	node * root = constructTree(in, post, 0, 7);
	levelOrder(root);
	// cout<<height(root);
	return 0;
}