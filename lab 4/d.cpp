#include <iostream>
#include <vector>
using namespace std;
//сумма уровней     
struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v): val(v), left(nullptr), right(nullptr) {}
};
Node* insert(Node*& root, int val, int level, vector<int>& levelsum, int& maxl) {
    if(!root) return root;
    if(level >= levelsum.size()) {
        levelsum.resize(level + 1);
    }
    levelsum[level] += val;
    if(val < root->val)
        insert(root->left, val, level + 1, levelsum, maxl);
    else
        insert(root->right, val, level + 1, levelsum, maxl);

    return root;

    
}

int main() {

    int n;
    cin >> n;
    vector<int> perm(n);
    for (int& x : perm) cin >> x;

    Node* root = nullptr;
    vector<int> levelSum;
    int maxLevel = 0;

    for (int val : perm)
        insert(root, val, 0, levelSum, maxLevel);

    cout << maxLevel + 1 << '\n';
    for (int i = 0; i <= maxLevel; ++i)
        cout << levelSum[i] << ' ';
    cout << endl;

    return 0;
}
