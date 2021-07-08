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

bool identical(node* tree1, node* tree2) {
	if(tree1 == NULL || tree2 == NULL) return tree1 == tree2;
	return identical(tree1->left, tree2->left) && identical(tree1->right, tree2->right); 
}

int main() {
	node* tree1 = build("true");
	node* tree2 = build("true");
	if(identical(tree1, tree2)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	return 0;
}
