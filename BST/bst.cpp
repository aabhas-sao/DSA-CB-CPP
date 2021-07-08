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

class BST {
private:
	node * root;
public:
	BST() {
		root = NULL;
	}

	void printBSTHelper(node * root) {
		if(root == NULL) {
			return;
		}
		cout<<root->data<<" ";
		printBSTHelper(root->left);
		printBSTHelper(root->right);
	}

	void printBST() {
		node * temp = root;
		printBSTHelper(temp);
	}

	node * find(int d) {
		node * temp = root;
		return findHelper(temp, d);
	}

	node * findHelper(node * root, int d) {
		if(root == NULL) {
			return NULL;
		}
		if(root->data == d) {
			return root;
		}
		node * left = findHelper(root->left, d);
		node * right = findHelper(root->right, d);
		
		if(left == NULL && right == NULL) {
			return NULL;
		}
		else if(left != NULL) {
			return left;
		} 
		return right;
	}

	void deleteNode(int d) {
		node * temp = root;
		node * toD = find(d);
		
		// leaf node
		if(toD->left == NULL && toD->right == NULL) {
			delete toD;
		}

		else {
			if(toD->right == NULL) {
				node * t3 = toD->left;
				toD->right = t3->right;
				toD->data = t3->data;
				toD->left = t3->left;
				toD->left = NULL;
				toD->right = NULL;
				delete toD;
			} else {
 				node * t2 = toD->right;
				while(t2->left != NULL) {
					t2 = t2->left;
				}
				toD->data = t2->data;
				delete t2;
			}		
		}
	}

	void insert(int d) {
		root = insertHelper(root, d);
	}

	node * insertHelper(node * root, int data) {
		if(root == NULL) {
			return new node(data);
		}

		if(data <= root->data) {
			root->left = insertHelper(root->left, data);
		}
		if (data > root->data) {
			root->right = insertHelper(root->right, data);
		}

		return root;
	}
};

int main() {
	BST bst;
	bst.insert(5);
	bst.insert(3);
	bst.insert(4);
	bst.insert(6);

	// bst.deleteNode(5);
	
	bst.printBST();
	// node * ans = bst.find(3);
	// cout<<"\n"<<ans->data;


	return 0;
}