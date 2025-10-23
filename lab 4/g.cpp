#include <iostream>
#include <vector>

using namespace std; // самый длинный путь в саб трии точнее между двумя узлами 

struct Node{
    int val;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v) {}
};

Node* insert(Node* root, int val) {
    if(!root) return new Node(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

int maxd = 0;
int puti(Node* root) {
    if(!root) return 0;
    int leftputi = puti(root->left);
    int rightputi = puti(root->right);
    maxd = max(maxd, leftputi + rightputi);
    return max(leftputi, rightputi) + 1;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;
    for(int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insert(root, val);
    }

    puti(root);

    cout << maxd + 1<< endl;
    return 0;

}