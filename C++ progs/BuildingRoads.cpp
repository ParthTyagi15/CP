#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

class DSU
{
    vector<int> par, rank, size;

public:
    DSU(int n)
    {
        par.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int findPar(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = findPar(par[node]);
    }

    void UnionSize(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if (size[pu] < size[pv])
        {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void UnionRank(int u, int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);

        if (rank[pu] < rank[pv])
        {
            par[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            par[pv] = pu;
        }
        else
        {
            par[pv] = pu;
            rank[pu]++;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU ds(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ds.UnionSize(a, b);
    }
    int cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (ds.findPar(i) == i)
        {
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt - 1 << endl;
    for (int i = 1; i <= cnt - 1; i++)
    {
        cout << ans[i] << " " << ans[i - 1] << endl;
    }
    return 0;
}