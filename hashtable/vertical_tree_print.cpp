#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* makeTreeFromLevelOrder() {
    queue<Node*> q;
    int x;
    cin >> x;
    Node* root = new Node(x);
    q.push(root);
    Node* temp;
    while(!q.empty()) {
        temp = q.front();
        cout << temp->data << " ";
        q.pop();
        cin >> x;
        if(x != -1) {
            temp->left = new Node(x);
            q.push(temp->left);
        }
        cin >> x;
        if(x != -1) {
            temp->right = new Node(x);
            q.push(temp->right);
        }
    }

    return root;
}

void verticalPrint(Node* root, int d, map<int, vector<int>>& m) {
    if(root == NULL) {
        return;
    }

    m[d].push_back(root->data);

    verticalPrint(root->left, d - 1, m);
    verticalPrint(root->right, d + 1, m);
}


int main() {
    int n;
    cin >> n;
    Node* root = makeTreeFromLevelOrder();
    map<int, vector<int>> m;
    verticalPrint(root, 0, m);
    cout << endl;
    for(auto x: m) {
        for(auto y: x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}