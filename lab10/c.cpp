#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, f;
    cin >> s >> f;

    const int MAXN = 40000;
    vector<int> dist(MAXN + 1, -1);
    vector<int> parent(MAXN + 1, -1);
    queue<int> q;

    if (s == f) {
        cout << 0 << "\n";
        return 0;
    }

    if (s > f) {
        cout << s - f << "\n";
        for (int i = s - 1; i >= f; i--) {
            cout << i << " ";
        }
        return 0;
    }

    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v * 2 <= MAXN && dist[v * 2] == -1) {
            dist[v * 2] = dist[v] + 1;
            parent[v * 2] = v;
            q.push(v * 2);
        }

        if (v - 1 > 0 && dist[v - 1] == -1) {
            dist[v - 1] = dist[v] + 1;
            parent[v - 1] = v;
            q.push(v - 1);
        }

        if (dist[f] != -1) break;
    }

    vector<int> path;
    int cur = f;

    while (cur != s) {
        path.push_back(cur);
        cur = parent[cur];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int x : path) {
        cout << x << " ";
    }

    return 0;
}