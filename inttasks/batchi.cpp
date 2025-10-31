#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int val) {
    if(!root) return;
    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
}
void findm(Node* root, int val){
    if(!root) return;
    Node* current = root;
    while(current->left != nullptr) {
        current = current->left;
    }
    cout << current->data << endl;
}
void findM(Node* root, int val){
    if(!root) return;
    Node* current = root;
    while(current->right != nullptr){
        current = current->right;
    }
    cout << current->data;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
}
void preorder(Node* root){
    if(!root) return;
    cout << root->data;
    preorder(root->left);
    preorder(root->right);

}
int size(Node* root) {
    if (!root) return 0;
    return 1 + size(root->left) + size(root->right);
}

int main() {
    
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    inorder(root);
    if()
}