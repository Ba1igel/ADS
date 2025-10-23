#include <iostream>
using namespace std;

struct Node{
    public:
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v) {}
};

Node* insert(Node* root, int val){
    if(!root) return new Node(val);
    if(val < root->val)
        root->left = insert(root->left, val);
    else   
        root->right = insert(root->right, val);
    return root;
}

Node* find(Node* root, int targ) {
    while(root && root-> val != targ) {
        root = (targ < root->val) ? root->left : root->right;
    }
    return root;

} 

int sbsizze(Node*root){
    if (!root) return 0;
    return 1 + sbsizze(root->left) + sbsizze(root->right);  
    // получаетсся текущий узел плюсь количество узлоыв и всио идет рекурсивно 

}
int main () {
    int n;
    cin >> n;
    Node* root = nullptr;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    int targ;
    cin >> targ;

    cout << sbsizze(find(root, targ)) << endl;
    return 0;
}
