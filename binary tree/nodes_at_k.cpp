#include <iostream>
#include <vector>
#include <algorithm>
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

int height(node * root) {
	if(root == NULL) {
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);

	return max(h1, h2) + 1;
}

void printLevelK(node * root, int k, vector<int>& ans) {
	if(root == NULL) {
		return;
	}

	if(k == 0) {
		ans.push_back(root->data);
		return;
	}

	printLevelK(root->left, k - 1, ans);
	printLevelK(root->right, k - 1, ans);
} 

int nodeAtK(node * root, int target, int k, vector<int>& ans) {
	if(root == NULL) {
		return -1;
	}

	if(root->data == target) {
		printLevelK(root, k, ans);
		return 0;
	}

	int l = nodeAtK(root->left, target, k, ans);
	if(l != -1) {
		if(l + 1 == k) {
			ans.push_back(root->data);
		}
		else {
			printLevelK(root->right, k - l - 2, ans);
		}
		return l + 1;
	}

	int r = nodeAtK(root->right, target, k, ans);
	if(r != -1) {
		if(r + 1 == k) {
			ans.push_back(root->data);
		}
		else {
			printLevelK(root->left, k - r - 2, ans);
		}
		return r + 1;
	}

	// not found in both subtrees
	return -1;
}

int main() {
	int n;
	cin >> n;
	int pre[n];
	int in[n];

	for(int i = 0; i < n; i++) {
		cin>>pre[i];
	}
	for(int i = 0; i < n; i++) {
		cin>>in[i];
	}

	node * root = treeFromPreIn(pre, in, 0, n - 1);


	int T;
	cin >> T;
	
	while(T--) {
		int target, k;
		cin >> target;
		cin >> k;
		vector<int> ans;
		nodeAtK(root, target, k, ans);
		sort(ans.begin(), ans.end());
		for(int x: ans) {
			cout << x << " ";
		}
		if(ans.size() == 0) {
			cout << "0";
		}
		cout << endl;
	}
	return 0;
}