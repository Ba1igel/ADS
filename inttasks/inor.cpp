#include <iostream>
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
    if(root == nullptr) return new Node(val);
    if(val < root->data) {
        root->left = insert(root->left, val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}
void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

}
void preorder(Node* root) {
    if(!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void FindMin(Node* root) {
    if(!root) return;
    Node* current = root;
    while(current->left != nullptr) {
        current = current->left;
    }
    cout << current->data << endl;
}

void FindMax(Node* root) {
    if(!root) return;
    Node* current = root;
    while(current->right != nullptr)  {
        current = current->right;
    } 
    cout << current->data << endl;
}

void search(Node* root, int target){
    if(!root || root->data == target) return;
    if(target < root->data) 
        return search(root->left, target);
    else   
        return search(root->right, target);
}

Node* delet(Node* root, int targ){
    if(!root) return nullptr;
    if(targ < root->data){
        return delet(root->left, targ);
    }
    else if(targ > root->data)
        return delet(root->right, targ);
    else {
        if(!root->left && !root->right){
            delete root;
            return nullptr;
        }
        else if(!root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        else{
            Node* succ = root->right;
            while(succ->left != nullptr) {
                succ = succ->left;
            }
            root->data = succ->data;
            root->right = delet(root->right, succ->data);
        }
    }
    return root;


}
int main() {
    int n; 
    cin >> n;
    Node *root = nullptr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }
    int m;
    postorder(root);
    preorder(root);
    inorder(root);
    root = delet(root, m);
    return 0;


}
