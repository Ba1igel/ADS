#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<bool> used(n + 1, false);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }

    int start, finish;
    cin >> start >> finish;

    queue<int> q;
    q.push(start);
    used[start] = true; 

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : adj[v]) {
            if (!used[to]) {
                used[to] = true;
                q.push(to);
            }
        }
    }

    if (used[finish])
        cout << "YES";
    else
        cout << "NO";

    return 0;
}