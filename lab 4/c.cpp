    #include <iostream>
    using namespace std;

    struct Node{
        public:
        int val;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int v) : val(v) {}
    };

    Node* insert(Node* root, int val) {
        if(!root) return new Node(val);
        if(val < root->val) {
            root->left = insert(root->left, val);
        }
        else
            root->right = insert(root->right, val);
        return root;   
    }


    Node* find(Node* root, int targ) {
        while(root && root->val != targ) {
            root = (targ < root->val) ? root->left : root->right;
        }
        return root;
    }

    void preOrder(Node *node) {
        if(node == NULL) 
            return;
        cout << node->val << " ";
        preOrder(node->left);
        preOrder(node->right);
    }



    int main () {
        int n;
        cin >> n;
        Node *root = nullptr;
        
        for(int i = 0; i < n; i++) {
            int val;
            cin >> val;
            root = insert(root, val);
        }

        int m;
        cin >> m;
        Node* nn = find(root, m);
        preOrder(nn);
        cout << endl;
    }

    // получается наша функция файнд ищет двойку, а потом через префикс мы выпускаем 2 1 3 ну крч саб трии
    