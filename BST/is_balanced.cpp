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

pair<int, bool> is_balanced(node * root) {
	if(root == NULL) {
		return make_pair(0, true);
	}

	pair<int, bool> h1 = is_balanced(root->left);
	pair<int, bool> h2 = is_balanced(root->right);

	bool ans = true;

	if(h1.second == false or h2.second == false) {
		ans = false;
	}

	if(abs(h1.first - h2.first) > 1) {
		ans = false;
	}

	return make_pair(max(h1.first,h2.first) + 1, ans);
}

int main() {
	node * root = build("true");
	bool ans = is_balanced(root).second;
	
	if(ans) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}

	return 0;
}