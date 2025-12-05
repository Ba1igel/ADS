#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);

    for (int k = 0; k < m; ++k) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;
    for (int v = 1; v <= n; ++v) {
        if (indeg[v] == 0)
            q.push(v);
    }

    vector<int> topo_order;
    topo_order.reserve(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo_order.push_back(u);

        for (int v : adj[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }

    if ((int)topo_order.size() != n) {
        cout << "Impossible\n";
    } else {
        cout << "Possible\n";
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ' ';
            cout << topo_order[i];
        }
        cout << '\n';
    }

    return 0;
}