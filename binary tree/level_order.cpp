#include<iostream>
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

node* build(string s){
	if(s=="true"){
        int d;
        cin>>d;
        node*root = new node(d);
        string l;
        cin>>l;
        
        if(l=="true") {
        	root->left = build(l);
        }
        string r;
        cin>>r;
        if(r=="true") {
        	root->right=build(r);
        }
        return root;
	}
	return NULL;
}

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

int main() {
	node * root = build("true");
	levelOrder(root);
	return 0;
}