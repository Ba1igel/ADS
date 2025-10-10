#include <iostream>
#include <string>
using namespace std;

struct Node {
    int val;
    int cnt = 1;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);
    if (x < root->val)
        root->left = insert(root->left, x);
    else if (x > root->val)
        root->right = insert(root->right, x);
    else
        root->cnt++; // увеличиваем количество копий
    return root;
}

Node* remove(Node* root, int x) {
    if (!root) return nullptr;
    if (x < root->val)
        root->left = remove(root->left, x);
    else if (x > root->val)
        root->right = remove(root->right, x);
    else {
        root->cnt--;
        if (root->cnt == 0) {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            Node* temp = root->right;
            while (temp->left) temp = temp->left;
            root->val = temp->val;
            root->cnt = temp->cnt;
            temp->cnt = 1;
            root->right = remove(root->right, temp->val);
        }
    }
    return root;
}

int count(Node* root, int x) {
    if (!root) return 0;
    if (x < root->val)
        return count(root->left, x);
    else if (x > root->val)
        return count(root->right, x);
    else
        return root->cnt;
}

int main() {
    int q;
    cin >> q;
    Node* root = nullptr;
    while (q--) {
        string cmd;
        int x;
        cin >> cmd >> x;
        if (cmd == "insert")
            root = insert(root, x);
        else if (cmd == "delete")
            root = remove(root, x);
        else if (cmd == "cnt")
            cout << count(root, x) << endl;
    }
    return 0;
}
