#include <iostream>
using namespace std;

class node {
public:
    node** children;
    node() {
        children = new node*[2];
        children[0] = NULL;
        children[1] = NULL;
    }
};

int* getBits(int n) {
    long long int mask = 1LL<<31;
    int* bits = new int[32]{0};
    int i = 0;
    
    while(mask != 0) {
        if(n & mask) {
            bits[i] = 1;
        } else {
            bits[i] = 0;
        }
        mask = mask>>1; 
        i++;
    }
    return bits;
}

class Trie {
    node* root;
public:
    Trie() {
        root = new node();
    }
    void insert(int n) {
        int* a = getBits(n);
        node* temp = root;

        for(int i = 0; i < 32; i++) {
            int ib = a[i];
            
            // if null create one
            if(temp->children[ib] == NULL) {
                temp->children[ib] = new node();
            }
            
            // go to next node
            temp = temp->children[ib];
        }
    }

    int maxXor() {
        node* temp = root;
        int a[32];
        int i = 0;

        while(temp != NULL) {
            cout << "--------" << endl;
            if(temp->children[0]) cout << 0 << endl;
            if(temp->children[1]) cout << 1 << endl;
            cout << "---------" << endl;
            if (temp->children[1] != NULL) {
                a[i] = 1;
                temp = temp->children[1];
            } else {
                a[i] = 0;
                temp = temp->children[0];
            }
            i++;
        }

        int mask = 1;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if(a[i] == 1) {
                ans += mask; 
            }
            mask = mask<<1;
        }

        return ans;
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

    for (int i = 0; i < n; i++) {
        t.insert(a[i]);
    }

    cout << t.maxXor() << endl;

    return 0;
}