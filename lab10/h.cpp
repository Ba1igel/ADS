#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n + 2, vector<char>(m + 2, '0'));
    vector<vector<bool>> used(n + 2, vector<bool>(m + 2, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    int ans = 0;
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == '1' && !used[i][j]) {
                ans++;
                queue<pair<int, int>> q;
                q.push({i, j});
                used[i][j] = true;

                while (!q.empty()) {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (!used[nx][ny] && grid[nx][ny] == '1') {
                            q.push({nx, ny});
                            used[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}