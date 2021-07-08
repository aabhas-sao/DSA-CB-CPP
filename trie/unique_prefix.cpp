#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    char data;
    bool terminated;
    unordered_map<char, node*> m;
    int visits;
    node(int d) {
        data = d;
        terminated = false;
        visits = 0;
    }
};

class Trie{
public:
    node* root;
    Trie() {
        root = new node('\0');
    }

    void insert(char word[]) {
        node* temp = root;
        for(int i = 0; word[i] != '\0'; i++) {
            char ch = word[i];
            // if word is present in hastable go to next and if not create
            if(temp->m.count(ch) == 0) {
                temp->m[ch] = new node(ch);
            }
            temp->visits++;
            temp = temp->m[ch];
        }
        temp->terminated = true;
    }

    bool search(char word[]) {
        node* temp = root;
        for(int i = 0; word[i] != '\0'; i++) {
            char ch = word[i];
            if(temp->m.count(ch) == 0) {
                return false;
            }
            temp = temp->m[ch];
        }
        if(temp->terminated == false) {
            return false;
        }

        return true;
    }
};

void soln(Trie t, int n, char words[][10]) {
    char* soln[n];

    for(int i = 0; i < n; i++) {
        soln[i] = new char[10];
    }

    for(int j = 0; j < n; j++) {
        char* word = words[j];
        node* temp = t.root;
        bool found = false;
        char* ans = new char[10];
        int i = 0;
        for(; word[i] != '\0'; i++) {
            temp = temp->m[word[i]];
            cout << word[i] << endl;
            cout << temp->visits << endl;
            ans[i] = word[i];
            if(temp->visits == 1) {
                found = true;
                break;
            }
        }
        if(!found) {
            ans[0] = '-';
            ans[1] = '1';
            ans[2] = '\0';
        }
        else ans[i] = '\0';
        soln[j] = ans;
    }

    for(int i = 0; i < n; i++) {
        cout << soln[i] << " ";
    }
}

int main() {
    Trie t;
    char words[][10] = {"dove", "dog", "dove", "love", "lover"};
    for(int i = 0; i < 5; i++) {
        t.insert(words[i]);
    }
    soln(t, 5, words);
}
