#include <iostream>
#include <unordered_map>
using namespace std;

class node {
public:
    char data;
    bool terminated;
    unordered_map<char, node*> m;
    node(int d) {
        data = d;
        terminated = false;
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
