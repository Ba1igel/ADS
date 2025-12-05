#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m + 1, vector<int>(n + 1));
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX));

    queue<pair<int, int>> q;

    int totalFresh = 0; 
    int converted = 0;
    int answer = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
            } else if (grid[i][j] == 1) {
                totalFresh++;
            }
        }
    }

    const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int x = cur.first;
        int y = cur.second;

        for (int k = 0; k < 4; k++) {
            int nx = x + dirs[k][0];
            int ny = y + dirs[k][1];

            if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                dist[nx][ny] = dist[x][y] + 1;
                answer = max(answer, dist[nx][ny]);
                converted++;
                q.push({nx, ny});
            }
        }
    }

    if (converted == totalFresh)
        cout << answer;
    else
        cout << -1;

    return 0;
}