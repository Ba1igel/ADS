#include <iostream>
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

int sum = 0;
void transform(Node* root) { // обход справа на ево большого к маленкому
    if (!root) return;
    transform(root->right);
    sum += root->val;
    root->val = sum;
    transform(root->left);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void reverse_inorder(Node* root) {
    if (!root) return;
    reverse_inorder(root->right);
    cout << root->val << " ";
    reverse_inorder(root->left);
}

int main() {
    int n;
    cin >> n;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    transform(root);
    reverse_inorder(root);
    cout << endl;
    return 0;
}
