#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    vector<int> sons(n + 1, 0);
    vector<bool> used(n + 1, false);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        g[l].push_back(r);
        g[r].push_back(l); 
        sons[l]++;
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            queue<int> q;
            q.push(i);
            used[i] = true;
            ans++;

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int to : g[v]) {
                    if (!used[to]) {
                        if (sons[v] < sons[to]) ans++;
                        used[to] = true;
                        q.push(to);
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}