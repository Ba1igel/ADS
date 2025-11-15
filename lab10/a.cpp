#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 1000;
int adj[MAXN][MAXN]; 
int m, n;            
int mushrooms = 0;

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};

int main() {
    cin >> m >> n;
    queue<pair<int, int>> q;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] == 2) q.push({i, j}); // стар товые позиции Mario
            if (adj[i][j] == 1) mushrooms++;    // считаем грибы
        }

    if (mushrooms == 0) {
        cout << 0 << endl;
        return 0;
    }

    int minutes = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (adj[nx][ny] == 1) {
                    adj[nx][ny] = 2;
                    mushrooms--;
                    q.push({nx, ny});
                }
            }
        }
        minutes++;
        if (mushrooms == 0) {
            cout << minutes << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
