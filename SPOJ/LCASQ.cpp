#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

const int maxN = 2e5 + 5;
const int LOG = 20;

vector<int> adj[maxN];
vector<int> depth(maxN);
vector<vector<int>> up(maxN, vector<int>(LOG));

void dfs(int node)
{
    for (auto it : adj[node])
    {
        up[it][0] = node;
        depth[it] = depth[node] + 1;
        for (int j = 1; j < LOG; j++)
            up[it][j] = up[up[it][j - 1]][j - 1];

        dfs(it);
    }
}

int get_lca(int a, int b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = LOG - 1; i >= 0; i--)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main()
{
    IOS;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++)
        {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    depth[0] = 0;
    dfs(0);
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }
    return 0;
}