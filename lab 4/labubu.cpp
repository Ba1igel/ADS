#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST {
    public:
    Node *root;

    BST() {
        root = NULL;

    }

    Node *insert(Node *node, int data) {
        if(node == NULL) {
            node = new Node(data);
            return node;
        }
        if (data <= node->data) {
            node->left = insert(node->left, data);
        }
        else{
            node->right = insert(node->right, data);
        }
        return node;
    }
}

int main () {
    return 0;
}