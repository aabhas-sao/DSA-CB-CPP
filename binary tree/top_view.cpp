#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;

	node(int val) {
		data = val;
		left = NULL;
		right = NULL;
	}		
};

node* maketree() {
	queue<node*> q;
	int d;
	cin >> d;

	node* root = new node(d);
	q.push(root);
	
	while(!q.empty()) {
		node* t = q.front();	
		
		if(t->left == NULL) {
			cin >> d;
			if(d != -1) {
				t->left = new node(d);
				q.push(t->left);
			}
		}
		
		if(t->right == NULL) {
			cin >> d;
			if(d != -1) {
				t->right = new node(d);
				q.push(t->right);
			}
		}
		q.pop();
	}

	return root;
}

void levelorder(node* root) {
	queue<node*> q;
	q.push(root);

	while(!q.empty()) {
		cout << q.front()->data << " ";
		node* t = q.front();
		if(t->left != NULL) {
			q.push(t->left);
		}
		if(t->right != NULL) {
			q.push(t->right);
		}

		q.pop();
	}
}

void leftWidth(node* root, int dist, int* max_dist) {
	if(root == NULL) {
		return;
	}	

	*max_dist = min(*max_dist, dist);

	leftWidth(root->left, dist - 1, max_dist);
	leftWidth(root->right, dist + 1, max_dist);
}

void rightWidth(node* root, int dist, int* max_dist) {
	if(root == NULL) {
		return;
	}

	*max_dist = max(*max_dist, dist);

	rightWidth(root->left, dist - 1, max_dist);
	rightWidth(root->right, dist + 1, max_dist);
}

void topViewRecursive(node* root, int pos, vector<int>& width, int lMax) {
	if(root == NULL) {
		return;
	}

	int i = pos + lMax;

	if(width[i] == -1) {
		width[i] = root->data;
	}

	topViewRecursive(root->left, pos - 1, width, lMax);
	topViewRecursive(root->right, pos + 1, width, lMax);
}

int main() {
	node* root = maketree();
	levelorder(root);
	cout << endl;
	int lMax = INT_MAX;
	int rMax = INT_MIN;

	leftWidth(root, 0, &lMax);
	rightWidth(root, 0, &rMax);

	vector<int> width(abs(lMax) + rMax + 1, -1);

	// cout << lMax << endl;
	// cout << rMax << endl;
	topViewRecursive(root, 0, width, abs(lMax));

	for(auto x: width) {
		cout << x << " ";
	}
	return 0;
}