    #include <iostream>
 

    using namespace std;

    struct Node {
        public:
        int val;
        Node* left = nullptr;
        Node* right = nullptr;
        Node (int v) : val(v) {}

    };

    Node* insert(Node* root, int val) {
        if(!root) return new Node(val);
        if(val < root->val)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    int CountBulk(Node* root) {
        if (!root) return 0;
        int count = 0;
        if(root->left && root->right){
            count++;
        }
        count += CountBulk(root->left);
        count += CountBulk(root->right);
        return count;
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

        cout << CountBulk(root) << endl;
        return 0;
    }