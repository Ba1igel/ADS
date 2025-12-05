#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, qu;
    cin >> n >> qu;

    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    while (qu--) {
        int x, y, z;
        cin >> x >> y >> z;

        bool ok1 = false, ok2 = false, ok3 = false;

        // Проверка ребер x-y и x-z
        for (int to : adj[x]) {
            if (to == y) ok1 = true;
            if (to == z) ok2 = true;
        }

        for (int to : adj[y]) {
            if (to == z) ok3 = true;
        }

        if (ok1 && ok2 && ok3)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}