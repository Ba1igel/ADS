#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};


Node* buildTree(const vector<int>& a, int l, int r) {
    if (l > r) return nullptr;
    int mid = (l + r) / 2;
    Node* root = new Node(a[mid]);
    root->left = buildTree(a, l, mid - 1);
    root->right = buildTree(a, mid + 1, r);
    return root;
}


void preorder(Node* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
}

int main() {
    int N;
    cin >> N;
    int size = (1 << N) - 1; 
    vector<int> a(size);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end()); 

    Node* root = buildTree(a, 0, size - 1); 
    vector<int> result;
    preorder(root, result); 

    for (int x : result) cout << x << ' ';
    cout << '\n';

    return 0;
}
