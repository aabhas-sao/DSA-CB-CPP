#include <iostream>
#include <queue>
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

int height(node * root) {
	if(root == NULL) {
		return 0;
	}

	int l = height(root->left);
	int r = height(root->right);

	return max(l, r) + 1;
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


void levelOrder(node * root) {
	int h = height(root);

	for(int i = 1; i <= h; i++) {
		printKthLevel(root, i);
		cout<<endl;
	}
}

node* buildTreeLevelWise(){

	int d;
	cin>>d;

	node*root = new node(d);
	queue<node*> q;
	q.push(root);

	while(!q.empty()){

		node*f = q.front();
		q.pop();
		int c1,c2;
		cin>>c1>>c2;

		if(c1!=-1){
			f->left = new node(c1);
			q.push(f->left);
		}
		if(c2!=-1){
			f->right = new node(c2);
			q.push(f->right);
		}
	}
	return root;
}

void leftView(node * root, int level) {
	static int maxLevel = -1;

	if(root == NULL) {
		return;
	}

	if(level > maxLevel) {
		cout << root->data << " ";
		maxLevel++;
	} 

	leftView(root->left, level + 1);
	leftView(root->right, level + 1);
} 

void rightView(node * root, int level) {
	static int maxLevel = -1;

	if(root == NULL) {
		return;
	}

	if(level > maxLevel) {
		cout << root->data << " ";
		maxLevel++;
	}

	rightView(root->right, level + 1);
	rightView(root->left, level + 1);
}

int main() {
	node* root = buildTreeLevelWise();
	rightView(root, 0);
	return 0;
}