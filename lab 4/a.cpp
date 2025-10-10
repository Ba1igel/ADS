#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v) {}
};


Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}


bool checkPath(Node* root, const string& path) {
    Node* curr = root;
    for (char dir : path) {
        if (!curr) return false;
        if (dir == 'L') curr = curr->left;
        else if (dir == 'R') curr = curr->right;
    }
    return curr != nullptr;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> bst(n);
    for (int i = 0; i < n; ++i) cin >> bst[i];

   
    Node* root = nullptr;
    for (int val : bst) root = insert(root, val);

   
    for (int i = 0; i < m; ++i) {
        string path;
        cin >> path;
        cout << (checkPath(root, path) ? "YES" : "NO") << endl;
    }

    return 0;
}
