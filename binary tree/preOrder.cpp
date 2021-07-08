#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct node {
	int data;
	node * left;
	node * right;
};

node * preOrder() {
	int d;
	cin>>d;

	if(d == -1) {
		return NULL;
	}

	node * root = new node();
	root->data = d;

	root->left = preOrder();
	root->right = preOrder();
	return root;
}

void print(node * root) {
		if(root == NULL) {
		return;
	}

	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
}

void inorder(node * root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void postorder(node * root) {
	if (root == NULL) {
		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int heightNode(node * root) {
	if(root == NULL) {
		return 0;
	}

	return max(heightNode(root->left), heightNode(root->right)) + 1;
}

void printKthLevel(node * root, int k) {
	if(root == NULL) {
		return;
	}
	if(k == 1) {
		cout<<root->data<<" ";
		return;
	}
	printKthLevel(root->left, k - 1);
	printKthLevel(root->right, k - 1);
}

void levelorder(node * root) {
	int h = heightNode(root);

	for (int i = 1; i <= h; i++) {
		printKthLevel(root, i);
	}
}

int diameterTree(node * root) {
	if(root == NULL) {
		return 0;
	}
	int h1 = heightNode(root->left);
	int h2 = heightNode(root->right);
	int a1 = h1 + h2;
	int a2 = diameterTree(root->left);
	int a3 = diameterTree(root->right);

	return max(a1, a2, a3);
}

pair<int, int> fastDiameter(node * root) {
	pair<int, int> p;
	if(root == NULL) {
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> p1 = fastDiameter(root->left);
	pair<int, int> p2 = fastDiameter(root->right);

	p.first = max(p1.first, p2.first) + 1;
	p.second = max(p1.first + p2.first, max(p2.second, p1.second));
	return p;
}

void levelorderIterative(node * root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	while(!q.empty()) {
		if(q.front() == NULL) {
			if(!q.empty()) {
				q.push(NULL);
				q.pop();
			}
			cout<<endl;
		}
		// print root and pop it out
		node * f = q.front();
		q.pop();
		cout<<f->data<<" ";

		// push root's children
		if(f->left != NULL) {
			q.push(f->left);
		}
		if(f->right != NULL) {
			q.push(f->right);
		}
	}
	cout<<q.front()->data;
	return;
}

int count(node * root) {
	if(root == NULL) {
		return 0;
	}
	return count(root->left) + count(root->right) + 1;
}

int sum(node * root) {
	if(root == NULL) {
		return 0;
	}
	return sum(root->left) + sum(root->right) + root->data;
}

int sumReplacement(node * root) {
	if(root == NULL) {
		return 0;
	}
	if(root->left == NULL && root->right == NULL) {
		return root->data;
	}

	int temp = root->data;
	root->data = sumReplacement(root->left) + sumReplacement(root->right);
	return root->data + temp;
}

int isHeightBalanced(node * root) {
	if(root == NULL) {
		return 0;
	}

	int balA = isHeightBalanced(root->left);
	int balB = isHeightBalanced(root->right);
	
	if(abs(balA - balB) <= 1 && balA != -1 && balB != -1) {
		return max(balA, balB) + 1;
	}
	return -1;
}

node* buildBalancedTreeFromArray(int a[], int s, int e) {
	if(s > e) {
		return NULL;
	}
	int mid = (s + e) / 2;
	node * root = new node();
	root->data = a[mid];
	root->left = buildBalancedTreeFromArray(a, s, mid - 1);
	root->right = buildBalancedTreeFromArray(a, mid + 1, e);

	return root;
}

int main() {
	node * root = preOrder();
	// int a[] = { 1, 2, 3, 4, 5};
	// int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	// int in = {3, 2, 8, 4, 1, 6, 7, 5};
	// int a[] = {1 2 6 -1 -1 -1 3 4 -1 -1 5 6 7 -1 -1};
	// postorder(root);
	// printKthLevel(root, 3);
	// cout<<heightNode(root);
	// levelorder(root);
	// levelorderIterative(root);
	// cout<<sum(root);
	// sumReplacement(root);
	// levelorderIterative(root);
	// cout<<endl;
	// cout<<isHeightBalanced(root);
	// node * root2 = buildBalancedTreeFromArray(a, 0, 4);
	// levelorderIterative(root2);
	cout<<diameterTree(root);
	return 0;
}