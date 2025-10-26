#include <iostream>
#include <vector>
using namespace std;
struct Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};
Node* insert(Node*& root, int val, int level, vector<int>& levelsum, int maxl) {
    if(!root) return root;
    if(level > levelsum.size()) {
        levelsum.resize(level + 1);
    }
    levelsum[level] += val;
    if(val < root->val) {
        insert(root->left, val, level + 1, levelsum, maxl);
    }
    else{
        insert(root->right, val, level + 1, levelsum, maxl);
    }
    return root;
}
void preorder(Node *root){
    if(!root) return;
    cout << root->val;
    preorder(root->left);
    preorder(root->right);
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Node* root = nullptr;
    vector<int> levelsum;
    int maxl = 0;
    for(int val : nums){
        insert(root, val, 0, levelsum, maxl);
    }
    cout << maxl + 1 << endl;
    for(int i = 0; i < maxl; i++) {
        cout << levelsum[i];
    }
    cout << endl;
    preorder(root);
    cout << endl;
}