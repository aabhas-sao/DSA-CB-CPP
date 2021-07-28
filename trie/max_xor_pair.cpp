#include <iostream>
using namespace std;

class node {
public:
    node* left;
    node* right;

    node() {
        left = NULL;
        right = NULL;
    }
};

class Trie {
    node* root;
public:
    Trie() {
        root = new node;
    }
    void insert(int n) {
        node* temp = root;

        for(int i = 31; i >= 0; i--) {
            if((n>>i) & 1) {
                if(temp->right == NULL) {
                    temp->right = new node();
                }
                temp = temp->right;
            } else {
                if(temp->left == NULL) {
                    temp->left = new node();
                }
                temp = temp->left;
            }
        }
    }

    int max_xor_helper(int value) {
        node* temp = root;
        int ans = 0;

        for ( int j = 31; j >= 0; j--) {
            int bit = (value >> j) & 1;

            if(bit == 0) {
                if ( temp->right != NULL) {
                    ans += (1<<j);
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            } else {
                if (temp->left != NULL) {
                    ans += (1<<j);
                    temp = temp->left;
                } else {
                    temp = temp->right;
                }
            }
        }

        return ans;
    }

    int max_xor(int a[], int n) {
        for (int i = 0; i < n; i++) {
            insert(a[i]);
        }
        int current = 0;
        int maxi = 0;
        
        for(int i = 0; i < n; i++) {
            current = max_xor_helper(a[i]);
            maxi = max(current, maxi);
        }

        return maxi;
    }

};



int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Logic

    Trie t;

    // create a prefix xor array
    for (int i = 1; i < n; i++) {
        a[i] ^= a[i - 1];
    }

    cout << t.max_xor(a, n) << endl;

    return 0;
}