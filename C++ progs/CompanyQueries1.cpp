#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
const int MOD = 1000000007;
using ll = long long;

int main()
{
    IOS;
    int n, q;
    cin >> n >> q;
    vector<int> parent(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> parent[i];
        parent[i]--;
    }
    parent[0] = 0;
    vector<int> depth(n + 1, 0);
    vector<vector<int>> up(n + 1, vector<int>(30, 0));
    for (int i = 1; i < n; i++)
    {
        up[i][0] = parent[i];
        depth[i] = depth[parent[i]] + 1;
    }
    for (int j = 1; j < 30; j++)
    {
        for (int i = 0; i < n; i++)
        {
            // if (up[i][j - 1] != -1)
            // {
            up[i][j] = up[up[i][j - 1]][j - 1];
            // }
        }
    }

    while (q--)
    {
        int x, k;
        cin >> x >> k;
        x--;
        if (depth[x] < k)
        {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < 30; i++)
        {
            if (k & (1 << i))
            {
                x = up[x][i];
            }
        }
        cout << x + 1 << endl;
    }
    return 0;
}
