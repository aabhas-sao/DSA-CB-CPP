#include <bits/stdc++.h>
using namespace std;

class node {
public:
	char a;
	int frequency;
	node* left;
	node* right;
	node(char x, int y) {
		a = x;
		frequency = y;
		left = NULL;
		right = NULL;
	}

	node(node* left, node* right) {
		this->left = left;
		this->right = right;
		a = '\0';
	}

	char getChar() const {
		return a;
	}

	int getFrequency() const {
		return frequency;
	}

	void setFrequency(const int f) {
		frequency = f;
	}
};

class NodeCompare {
public:
	bool operator()(node* n1, node* n2) {
		return n1->getFrequency() > n2->getFrequency();
	}
};

class HuffmanEncoder {
	unordered_map<char, string> encoder;
	unordered_map<string, char> decoder;
	unordered_map<char, int> u;
	priority_queue<node*, vector<node*>, NodeCompare> pq;
	node* root;
	string source;
	string encodedString;
public:
	HuffmanEncoder(string s) {
		source = s;
		for (int i = 0; i < source.length(); i++) {
			u[source[i]]++;
		}

		// prepare min heap
		for (auto x : u) {
			node* n =  new node(x.first, x.second);
			pq.push(n);
		}

		//prepare tree while only one element remains in heap
		while (pq.size() != 1) {
			auto n1 = pq.top();
			pq.pop();
			auto n2 = pq.top();
			pq.pop();

			// cout << n1.getFrequency() << endl;

			node* combined = new node(n1, n2);
			combined->setFrequency(n1->getFrequency() + n2->getFrequency());
			pq.push(combined);
		}

		node* p = pq.top();
		fillEncoderDecoder(p, "");
		encode();
	}

	//preorder traversal
	void fillEncoderDecoder(node* root, string s) {
		if (root == NULL) {
			return;
		}

		if (root->left == NULL && root->right == NULL) {
			encoder[root->getChar()] = s;
			decoder[s] = root->getChar();
			return;
		}

		if (root->left != NULL) {
			fillEncoderDecoder(root->left, s + "0");
		}

		if (root->right != NULL) {
			fillEncoderDecoder(root->right, s + "1");
		}
	}

	bitset<12> encode() {
		encodedString = "";
		for (int i = 0; i < source.length(); i++) {
			encodedString += encoder[source[i]];
		}
		bitset<12> b;
		for (int i = encodedString.length(); i >= 0; i--) {
			if (encodedString[i] == '1') {
				b.set(i);
			}
		}
		return b;
	}

	string decode() {
		string res = "";
		string rv = "";
		for (int i = 0; i < encodedString.length(); i++) {
			rv += encodedString[i];
			if (decoder.count(rv) == 1) {
				res += decoder[rv];
				rv = "";
			}
		}

		return res;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string src;
	cin >> src;
	HuffmanEncoder hf(src);
	cout << hf.encode() << endl;
	cout << hf.decode();
	return 0;
}