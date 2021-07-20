#include <iostream>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

class Node {
public:
    char c;
    map<char, Node*> m;
    bool closed;

    Node(char c) {
        this->c = c;
        closed = false;
    }
};

class Trie {
public:
    Node* root;

    Trie() {
        root = new Node('\0');
    }

    void insert(string s) {
        Node* temp = root;
        for(int i = 0; i < s.length(); i++) {
            if(temp->m.count(s[i]) == 0) {
                temp->m[s[i]] = new Node(s[i]);
            }
            temp = temp->m[s[i]];
        }
        temp->closed = true;
    }
    void printAll(Node* root, int i, char c[]) {
        if(root->closed == true) {
            c[i] = root->c;
            c[i + 1] = '\0';
            cout << c << endl;
        }
        
        c[i] = root->c;
        for(auto x: root->m) {
            printAll(x.second, i + 1, c);
        }
    }
    void matches(string prefix, char c[]) {
        Node * temp = root;
        int i = 0;
		bool nos = false;
        for(; i < prefix.length(); i++) {
            if(temp->m.count(prefix[i]) == 0) {
				nos = true;
				break;
			}
			temp = temp->m[prefix[i]];
            c[i] = temp->c;
            // cout << temp->c << endl;
        }
		if(nos) {
			cout << "No suggestions" << endl;
            insert(prefix);
			return;
		}
        // cout << i << endl;
        if(temp->closed) {
            c[i] = '\0';
            cout << c << endl;
        }
        for(auto x: temp->m) {
            printAll(x.second, i, c);
        }
    }
};

int main() {
    Trie t;
    Node* root = t.root;
    char c[1000000];
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        t.insert(s);
    }
    int p;
    cin >> p;
    while(p--) {
        string prefix;
		cin >> prefix;
        for(int i = 0; i < n; i++) {
            prefix[i] = tolower(prefix[i]);
        }
        t.matches(prefix, c);
    }

    return 0;
}