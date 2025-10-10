#include <iostream>
#include <vector>

using namespace std;

struct Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node*& root, int val, int level, vector<int>& levelc, int& maxl) {
    if(!root) {
        root = new Node(val);
        maxl = max(maxl, level);
        if(level >= levelc.size()){
            levelc.resize(level + 1);
        }
        levelc[level]++;
        return root;
    }
    if(val < root->val)
        insert(root->left, val, level + 1, levelc, maxl);
    
    else if(val > root->val)
        insert(root->right, val, level + 1, levelc, maxl);
    return root;

}


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    Node* root = nullptr;
    int maxlevel = 0;
    vector<int> levelc;

    for (int x : a)
        insert(root, x, 0, levelc, maxlevel);
    

    int w = 0;
    for(int i = 0; i < levelc.size(); ++i)
        w = max(w, levelc[i]);
    cout << maxlevel << '\n';
    return 0;
}