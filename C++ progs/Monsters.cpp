#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inbound(int nx, int ny, int n, int m)
{
    return (nx >= 0 and nx < n and ny >= 0 and ny < m);
}

char from[1001][1001];
char ans[1001 * 1001];

void printSol(int x, int y, int d)
{
    // cout << x << " " << y << endl;
    for (int i = d - 1; i >= 0; i--)
    {
        ans[i] = from[x][y];
        // cout << x << " "  << y << endl;;
        if (ans[i] == 'U')
            x++;
        else if (ans[i] == 'L')
            y++;
        else if (ans[i] == 'D')
            x--;
        else if (ans[i] == 'R')
            y--;
    }
    for (int i = 0; i < d; i++)
    {
        cout << ans[i];
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    pair<int, int> src;
    vector<pair<int, int>> mon;
    vector<vector<char>> lb(n, vector<char>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    memset(from, '!', sizeof(from));
    queue<pair<int, int>> q; // x,y
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lb[i][j];
            if (lb[i][j] == 'A')
            {
                src = {i, j};
            }
            if (lb[i][j] == 'M')
            {
                vis[i][j] = 1;
                q.push({i, j});
            }
            if (lb[i][j] == '#')
                vis[i][j] = 1;
        }
    }
    while (!q.empty())
    {
        auto coord = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = coord.first + dx[i];
            int ny = coord.second + dy[i];
            if (inbound(nx, ny, n, m) and !vis[nx][ny])
            {
                dist[nx][ny] = dist[coord.first][coord.second] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == 0)
                dist[i][j] = 1e9;
            vis[i][j] = (lb[i][j] == '#');
        }
    }
    // cout << "dist1\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << dist[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "vis\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    vis[src.first][src.second] = 1;
    q.push(src);
    vector<vector<int>> dist2(n, vector<int>(m, 0));
    while (!q.empty())
    {
        auto coord = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = coord.first + dx[i];
            int ny = coord.second + dy[i];

            if (inbound(nx, ny, n, m) and vis[nx][ny] == 0 and dist2[coord.first][coord.second] + 1 < dist[nx][ny])
            {
                if (i == 0)
                    from[nx][ny] = 'R';
                else if (i == 1)
                    from[nx][ny] = 'D';
                else if (i == 2)
                    from[nx][ny] = 'L';
                else if (i == 3)
                    from[nx][ny] = 'U';
                dist2[nx][ny] = dist2[coord.first][coord.second] + 1;
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    // cout << "from\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << from[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < n; i++)
    {
        if (lb[i][0] != '#' and lb[i][0] != 'M' and vis[i][0])
        {
            cout << "YES\n"
                 << dist2[i][0] << endl;
            printSol(i, 0, dist2[i][0]);
            return 0;
        }
        else if (lb[i][m - 1] != '#' and lb[i][m - 1] != 'M' and vis[i][m - 1])
        {
            cout << "YES\n"
                 << dist2[i][m - 1] << endl;
            printSol(i, m - 1, dist2[i][m - 1]);
            return 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (lb[0][i] != '#' and lb[0][i] != 'M' and vis[0][i])
        {
            cout << "YES\n"
                 << dist2[0][i] << endl;
            printSol(0, i, dist2[0][i]);
            return 0;
        }
        else if (lb[n - 1][i] != '#' and lb[n - 1][i] != 'M' and vis[n - 1][i])
        {
            cout << "YES\n"
                 << dist2[n - 1][i] << endl;
            printSol(n - 1, i, dist2[n - 1][i]);
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
