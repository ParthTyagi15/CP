#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

const ll maxN = (int)500;

const ll INF = 0x3f3f3f3f3f3f3f3f;

ll mat[maxN + 1][maxN + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, q;
    cin >> n >> m >> q;
    memset(mat, INF, sizeof(mat));
    for (int i = 0; i <= n; i++)
    {
        mat[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        ll u, v, wt;
        cin >> u >> v >> wt;
        mat[u][v] = min(mat[u][v], wt);
        mat[v][u] = min(mat[v][u], wt);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << (mat[a][b] >= INF ? -1 : mat[a][b]) << endl;
    }
    return 0;
}
