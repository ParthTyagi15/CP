#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int sx = 0, sy = 0, ex = 0, ey = 0;
    vector<vector<char>> v(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            else if (v[i][j] == 'B')
            {
                ex = i;
                ey = j;
            }
            else if (v[i][j] == '#')
            {
                vis[i][j] = 1;
            }
        }
    }
    vector<vector<int>> path(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    vis[sx][sy] = 1;
    queue<pii> q;
    q.push({sx, sy});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int x = it.first;
        int y = it.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and vis[nx][ny] == 0)
            {
                if (i == 0)
                    path[nx][ny] = 'U';
                else if (i == 1)
                    path[nx][ny] = 'R';
                else if (i == 2)
                    path[nx][ny] = 'D';
                else if (i == 3)
                    path[nx][ny] = 'L';
                dist[nx][ny] = dist[x][y] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (vis[ex][ey] == 0)
    {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<char> ans(1000000);
    cout << dist[ex][ey] << "\n";
    pii p = {ex, ey};
    for (int i = dist[ex][ey]; i > 0; i--)
    {
        ans[i] = path[p.first][p.second];
        if (ans[i] == 'D')
            p = {p.first - 1, p.second};
        else if (ans[i] == 'U')
            p = {p.first + 1, p.second};
        else if (ans[i] == 'L')
            p = {p.first, p.second + 1};
        else if (ans[i] == 'R')
            p = {p.first, p.second - 1};
    }
    for (int i = 1; i <= dist[ex][ey]; i++)
        cout << ans[i];
    cout << endl;
    return 0;
}