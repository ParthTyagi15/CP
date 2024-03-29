#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

const int maxN = 2e5 + 5;
const int LOG = 20;

vector<int> parent(maxN);
vector<int> depth(maxN);
vector<vector<int>> up(maxN, vector<int>(LOG));


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
    int n, q;
    cin >> n >> q;
    parent[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        // parent[i]--;
    }

    for(int i = 2; i <= n; i++){
        up[i][0] = parent[i];
        depth[i] = depth[parent[i]] + 1;
    }

    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            up[i][j] = up[up[i][j - 1]][j - 1];
        }
    }
    
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << endl;
    }
    return 0;
}